#include <iostream>
#include <string>
#include <algorithm>
#define DEBUG(a) std::cout << #a "=[" << a << "]" << std::endl;
/**
There are 3 edits: insert char, remove char, and raplace char. given two functions determine if they are 0 or 1 edit awawy
*/

bool is_relative(std::string const& string_a,  std::string const& string_b)
{
  std::string sorted_str_a(string_a);
  std::string sorted_str_b(string_b);
  unsigned int difference_in_length(0);
  unsigned int difference_in_chars(0);

  sort(sorted_str_a.begin(),sorted_str_a.end());
  sort(sorted_str_b.begin(),sorted_str_b.end());

  // In case they are the same
  if (sorted_str_a == sorted_str_b)
        return true;

  // In case they are not
  difference_in_length= abs(sorted_str_a.size() -sorted_str_b.size());

  int min_lentgth = sorted_str_a.size()>sorted_str_b.size() ? sorted_str_a.size() : sorted_str_b.size();

  for (int i=0; i<min_lentgth; i++)
    if (sorted_str_a[i]!=sorted_str_b[i])
      ++difference_in_chars;

  DEBUG(difference_in_length);
  DEBUG(difference_in_chars);

  if (difference_in_length <=1 && difference_in_chars==0)
      return true;

  return false;
}

int main()
{
  std::string str_a("caot");
  std::string str_b("cbat");

  std::cout << "RESULT:" << is_relative(str_a, str_b);
}
