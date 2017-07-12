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
bool read_from_file=true;

//NB get rid of the below
class elements{
public:
  vector <int> values;
};

class SeqList{
  int LastAnswer;
public:
  SeqList(int N):LastAnswer(0)
   {SeqListArray.resize(N);
    size_N=N;
    assert(SeqListArray.size()==size_N);
   };
  int ElementAppend(int position, int value);
  int ElementRemove(int position);
  int PrintLists(void);
  void Action(int action, int x, int y);
private:
  unsigned int size_N;
  vector<elements> SeqListArray;
};

void SeqList::Action(int action, int x, int y)
{
  int xor_result =  x ^ LastAnswer;
  if (debug_mode)
    DEBUG(xor_result);
  assert(size_N >0);
  unsigned int seq = xor_result % size_N;
  if (debug_mode)
    DEBUG(seq);
  assert(seq >=0);
  assert(seq <size_N);


  switch(action) {
    case 1: // Action 1
           if (debug_mode)
             cout << "Action 1: Adding "<<y<<" into "<<seq<<" sequence"<<endl;
            ElementAppend(seq, y);
            break;
    case 2:{
            //Action 2
              int seq_size = SeqListArray[seq].values.size();
              assert(seq_size>=0);
              if (debug_mode)
                DEBUG(seq_size);

              int location = y % seq_size;
              int result = SeqListArray[seq].values[location];
              //
              if (debug_mode)
                cout << "Action 2: Updatig LastAnswer with "<< result <<endl;
            LastAnswer = result;
            cout << LastAnswer << endl;
            break;};
    default: // compilation error: jump to default: would enter the scope of 'x'
             // without initializing it
             std::cout << "Error - incorrect action: \n" << action <<x << y<<endl;
             break;
  }
}

int SeqList::PrintLists()
{
  int n=SeqListArray.size();
  if (debug_mode)
    cout << "Printing whole sequence list of size "<< n<< ";"<<endl;

  for (int i=0; i<n; ++i)
  {
    cout << "Printing sequence number "<< i <<":";
    int m = SeqListArray[i].values.size();
    for (int j=0;j<m; ++j)
      cout << SeqListArray[i].values[j] <<" ";
    cout << ";"<<endl;
  }
  return 0;
}

int SeqList::ElementRemove(int position)
{
  if (debug_mode)
    cout << "Removin last element from "<<position<<" sequence"<<endl;

  int last_element = SeqListArray[position].values.back();
  SeqListArray[position].values.pop_back();

  return last_element;
}


int SeqList::ElementAppend(int position, int value)
{
  if (debug_mode)
    cout << "Adding element "<< value << " into "<<position<<" sequence"<<endl;

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
    string query;

    if (read_from_file)
    {
      testcase.open("/home/kip_morgan/git_projects/git-projects/hacker_rank_data_structures/dynamic_array/test_case.input");
      getline(testcase,query);
      stringstream stream(query);
      stream >> N;
      stream >> Q;
    }
    else
    {
      getline(cin,query);
      stringstream stream(query);
      stream >> N;
      stream >> Q;
    }


    assert(N>=1);
    assert(Q<=100000);


    if (debug_mode)
      {DEBUG(N);DEBUG(Q);}

    SeqList SupaList(N);

    //Looping through queries
    for (int i=0; i<Q; ++i)
    {
      if (read_from_file)
        getline(testcase,query);
      else
        getline(cin,query);

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

      SupaList.Action(st,nd,rd);

      if (debug_mode)
        SupaList.PrintLists();
    }

    testcase.close();
    // Returning the result

    return 0;
}
