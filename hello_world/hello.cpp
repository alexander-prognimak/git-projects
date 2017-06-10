#include <iostream>

using namespace std;

struct Hello{
 int n; //number of times to greet
 string  greeting; // Hello World

 void initialize(int num, char* greet)
 {
   n=num;
   greeting=greet;
 }

  void create()
  {
    n=0;
    greeting = "Hello World";
  }

  void destroy()
  {
    n=0;
    greeting = "";
  }
};

 int main()
 {
  std::cout << "Hello World bitches v0.5!";
  return 0;
 }
