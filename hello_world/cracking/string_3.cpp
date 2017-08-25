#include <iostream>
#include <string>

/*
  Given true length(covering change) of string change all spaces to %20
*/

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if(from.empty())
        return;

    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main()
{
  std::string url("Mr John Smith");
  const int n(13);

  int start_pos=0;
  while(start_pos<n)
  {
    size_t found=url.find(" ", start_pos);
    if (found!=std::string::npos)
    {
      url.replace(found,1,"%20");
      start_pos =found +3;
    }
  }

  std::cout << url;
}
