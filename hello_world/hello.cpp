#include <iostream>

using namespace std;

struct Hello{
 int n; //number of times to greet
 string  greeting; // greeeting line

 void initialize(int num, char* greet)
 {
   n=num;
   greeting=greet;
 }

  void create()
  {
    n=0;
    greeting = "Hello world!!!";
  }

  void destroy()
    n=0;
    greeting = "";
  }

  void show_greeting()
  {
    for (int i=0; i<n; i++)x
      std::cout << greeting;
  }
};

 int main()
 {
  Hello alloha;
  alloha.create();
  alloha.initialize(1,"Hello World bitches v0.1!");
  alloha.show_greeting();
  alloha.destroy();
  return 0;
 }
