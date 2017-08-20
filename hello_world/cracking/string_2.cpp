#include <iostream>
#include <string>
#include <algorithm>

/*
  Given two strings, write a metthod to decide if one is a permutation of another
*/

bool is_permutation(std::string const&  str1, std::string const&  str2)
{
  if (str1.size() != str2.size())
    return false;

  std::string sorted_string1=str1;
  sort(sorted_string1.begin(),sorted_string1.end());

  std::string sorted_string2=str2;
  sort(sorted_string2.begin(),sorted_string2.end());

  if (sorted_string1!=sorted_string2)
    return false;

  return true;
}

int main ()
{
  std::string str1("abcd");
  std::string str2("bcad");

  std::cout << is_permutation(str1,str2);

  return 0;
}
