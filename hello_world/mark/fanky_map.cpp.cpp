#include <set>
#include <iostream>

using namespace std;

struct greater1{
  bool operator()(string a, string b)
  {
    return a>b;
  };
};


int main(void){

  std::set<std::string, greater1> set_of_strings;
  set_of_strings.insert("one");
  set_of_strings.insert("two");
  set_of_strings.insert("three");

  //for (std::set<std::string>::const_iterator i = set_of_strings.begin(); i!=set_of_strings.end(); ++i)
  for (auto i:set_of_strings)
    std::cout <<  i << std::endl;

}
