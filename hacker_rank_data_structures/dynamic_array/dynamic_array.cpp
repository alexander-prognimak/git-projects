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

bool debug_mode=false;

//NB get rid of the below
class elements{
public:
  vector <int> values;
};

class SeqList{
  int LastAnswer;
public:
  SeqList(int N):LastAnswer(0)
   {SeqListArray.reserve(N);};
  int ElementAppend(int position, int value);
  int PrintSeqList(void);
  int ElementRemove(int position);
private:
  int size_N;
  vector<elements> SeqListArray;
};

int SeqList::PrintSeqList()
{
  int n=SeqListArray.size();

  for (int i=0; i<n; ++i)
  {
    int m=SeqListArray[i].values.size();
    for (int j=0;j<m; ++j)
      cout << SeqListArray[i].values[j];
    cout << endl;
  }

  return 0;
}

int SeqList::ElementRemove(int position)
{
  int last_element = SeqListArray[position].values.back();
  SeqListArray[position].values.pop_back();

  return last_element;
}


int SeqList::ElementAppend(int position, int value)
{
  SeqListArray[position].values.push_back(value);
  return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // declarations
    int N, Q;

    // Reading N(number of sequences) and Q(number of queries)
    //From file
    ifstream testcase;
    testcase.open("test_case.input");
    string query;
    getline(testcase,query);
    stringstream stream(query);
    stream >> N;
    stream >> Q;

    assert(N>=1);
    assert(Q<=100000);


    if (debug_mode)
      {DEBUG(N);DEBUG(Q);}

    SeqList SupaList(N);

    //Looping through queries
    for (int i=0; i<Q; ++i)
    {
      getline(testcase,query);
      stringstream stream(query);
      int st;
      long nd,rd;
      stream >> st;
      stream >> nd;
      stream >> rd;

      //Checks
      assert(st>0 && st<3);
      assert( nd>=0 && nd<=1000000000);
      assert( rd>=0 && rd<=1000000000);

      if (debug_mode)
        {DEBUG(st);DEBUG(nd);DEBUG(rd);}

    }

    testcase.close();
    // Returning the result

    return 0;
}
