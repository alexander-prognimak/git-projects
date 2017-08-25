#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


struct greater1{
  bool operator()(string a, string b)
  {
    return a>b;
  };
};

int main(void)
{
  bool c=false;
  std::vector<std::string> vector_of_strings{"one","three","two"};

//capture list
  std::sort(vector_of_strings.begin(),vector_of_strings.end(), [c](string a, string b)  {return c?(a>b):(a<b);});

  for (auto i:vector_of_strings)
    std::cout <<  i << std::endl;

}
