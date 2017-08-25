#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

/*
 Check if given string is a permutations of polindrome
*/

//palindrom check function
bool is_polindrom(std::string const& string_pp)
{
    int unique(0);
    int curr_pos(0);
    char curr_chr('!');
    std::string str_pp = string_pp;

    do
    {
      assert(str_pp.size()-1>=0);

      curr_pos = str_pp.size()-1;
      curr_chr = str_pp[curr_pos];
      str_pp.erase(curr_pos);

      //debug
      //std::cout << str_pp << "!"<< curr_pos <<std::endl;

      curr_pos = str_pp.find(curr_chr);
      if (curr_pos == std::string::npos )
        {++unique; //std::cout<< "DEBUG:" << curr_chr << " not found!";
        }
      else
      {
        //std::cout << "DEBUG:" << curr_pos << "|" << std::string::npos << "UNQ:" << unique << std::endl;
        str_pp.erase(curr_pos,1);
      }
    }while((str_pp.size()>0)&&(unique<=2));

    if ((unique<2) && (unique>0))
      return true;
    else
      return false;

}

int main()
{
  //potential_palindrom
  std::string str_pp("tact coa");
  str_pp.erase(std::find(str_pp.begin(), str_pp.end(), ' '));
  std::cout << "RESULT:" << is_polindrom(str_pp);
}
