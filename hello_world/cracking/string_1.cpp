#include <iostream>
#include <string>
#include <vector>

int main()
{
 // Check for duplicate symbols
 // assuming only A-Z and a-z are present
  std::string test_string("Abcdefgfhtryr");
  std::vector<bool> alphabet(57);

  for(auto i=test_string.cbegin();i<test_string.cend(); i++)
  {
    int asc_code = (int)*i;
    if (!alphabet[asc_code])
        alphabet[asc_code] = 1;
    else
      std::cout << "Duplicate " << *i << " found\n";
  }

  return 0;
}
