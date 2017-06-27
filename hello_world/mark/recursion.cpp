#include <iostream>
#include <assert.h>

void print_character(int N)
{
  int dividor =0;

  char roman = 'A';
  //cant remember switch syntax
  if (N>1000)
    {dividor=1000; roman='M';}
  else if (N>500)
    {dividor=500; roman='D';}
  else if (N>100)
   {dividor=100; roman='C';}
  else if (N>50)
  {dividor=50; roman='L';}
  else if (N>10)
   {dividor=10; roman='X';}
  else {dividor=1; roman='I';};

  assert(dividor!=0);
  assert(roman!='A');

  int whole = N / dividor;
  int remain = N  %  dividor;

  for (int i=0;i<whole;++i)
     std::cout<< roman;

  if (remain>0)
    print_character(remain);
  else
   std::cout<<std::endl;
}

int main()
{
 int N= 4572;
 print_character(N);
}
