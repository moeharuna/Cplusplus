
#include <iostream>
#include <vector>
#include <tuple>

typedef std::vector<std::vector<int>> matrix;

matrix result(matrix &m1, matrix &m2)
{
  matrix result;

  result.resize(m1.size());
  for(int i=0; i<result.capacity(); ++i)
    result[i].resize(m2.at(0).size(), 0);

  for(int i=0; i<m1.size(); ++i)
      for(int c2=0; c2<m2.at(0).size(); ++c2)
          for(int r2=0; r2<m2.size(); ++r2)
            {
              result[i][c2]+=m1[i][r2]*m2[r2][c2];
            }
  return result;
}


std::tuple<int, int, int, int> input()
{
  int rowc1, colc1, rowc2, colc2;
  std::cout<<"Enter matrix size, row count and column count for first matrix:\n";
  std::cin>>rowc1>>colc1;
  std::cout<<"For second:\n";
  std::cin>>rowc2>>colc2;
  return std::make_tuple(rowc1, colc1, rowc2, colc2);
}

int main()
{
  int rowc1, colc1, rowc2, colc2;
  matrix mat1, mat2;

  do{
      auto inp = input();

      rowc1 = std::get<0>(inp);
      colc1 = std::get<1>(inp);
      rowc2 = std::get<2>(inp);
      colc2 = std::get<3>(inp);

    }while(colc1!=rowc2);

  std::cout<<"Enter first matrix values:\n";

  mat1.resize(rowc1);
  for(int r=0; r<rowc1; ++r)
      for(int c=0; c<colc1; ++c)
        {
          int val;
          std::cin>>val;
          mat1[r].push_back(val);
        }
  std::cout<<"enter second:\n";

  mat2.resize(rowc2);
  for(int r=0; r<rowc2; ++r)
      for(int c=0; c<colc2; ++c)
        {
          int val;
          std::cin>>val;
          mat2[r].push_back(val);
        }
  matrix answer = result(mat1, mat2);

  std::cout<<"Result: \n";
  for(auto i :answer)
    {
      for(auto j :i)
          std::cout<<j<<" ";
      std::cout<<"\n";
    }
}
