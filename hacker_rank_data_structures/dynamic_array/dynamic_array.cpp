#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

#define DEBUG(a) cout << #a "=[" << a << "]" << endl;


//NB get rid of the below
class elements{
public:
  vector <int> values;
};

class SeqList{
public:
  SeqList(int N);
  int ElementAppend(int position, int value);
  int PrintSeqList(void);
  int LastAnswer;

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

int SeqList::ElementAppend(int position, int value)
{
  int new_node_size = SeqListArray[position].values.size()+1;
  SeqListArray[position].values.reserve(new_node_size);
  SeqListArray[position].values[new_node_size] = value;
  return 0;
}


SeqList::SeqList(int N)
{
  LastAnswer=0;
  SeqListArray.reserve(N);
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

    DEBUG(N);

    SeqList SupaList(N);

    for (int i=0; i<Q; ++i)
    {
      getline(testcase,query);
      stringstream stream(query);
      int st,nd,rd;
      stream >> st;
      stream >> nd;
      stream >> rd;
      cout <<  "DEBUG!"<<st<<" "<<nd<<" "<<rd<<"!"<<endl;
    }
    testcase.close();
    /* From console
    cin >> N >> Q;
    for (int i=0; i<Q; ++i)
    {
      cin >>
    } */
    //Looping through queries

    // Returning the result

    return 0;
}
