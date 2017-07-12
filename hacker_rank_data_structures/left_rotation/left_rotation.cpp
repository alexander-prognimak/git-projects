#include <cmath>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


using namespace std;

#define DEBUG(a) cout << #a "=[" << a << "]" << endl;
bool debug_mode=true;
bool read_from_file=true;

//NB get rid of the below

void rotate_vector(int D, vector<int> &numbers)
{
  int first_element(0);
  for (int i=0;i<D;++i)
  {
    first_element= numbers[0];
    //assert(first_element>0);
    numbers.erase(numbers.begin());
    numbers.push_back(first_element);
  }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // declarations
    int N, D;

    // Reading N(number of sequences) and D(number of queries)
    ifstream testcase;
    string query;

    if (read_from_file)
    {
      testcase.open("/home/kip_morgan/git_projects/git-projects/hacker_rank_data_structures/left_rotation/test_case.input");
      getline(testcase,query);
      stringstream stream(query);
      stream >> N;
      stream >> D;
    }
    else
    {
      getline(cin,query);
      stringstream stream(query);
      stream >> N;
      stream >> D;
    }

    assert(N<=10000);
    assert(N>=1);
    assert(D>=1);
    assert(D<=10000);

    if (debug_mode)
      {DEBUG(N);DEBUG(D);}

    vector<int> numbers;

    //Reading vector
    if (read_from_file)
      getline(testcase,query);
    else
      getline(cin,query);

    stringstream stream(query);

    int num;
    for (int i=0; i<N;i++)
    {
      stream >> num;
      numbers.push_back(num);
    }

    if (debug_mode)
    {
      for (unsigned int i = 0; i<numbers.size(); ++i)
      std::cout << numbers[i] << ' ';
    }
    cout<<endl;
    rotate_vector(D,numbers);

    if (debug_mode)
    {
      for (unsigned int i = 0; i<numbers.size(); ++i)
      std::cout << numbers[i] << ' ';
    }
    cout<<endl;

    testcase.close();
    // Returning the result

    return 0;
}
