#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

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
  int LastAnswer = 0;

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
    string qn;
    getline(testcase,qn);
    stringstream stream(qn);
    stream >> N >> Q;
    cout << "DEBUG:" << N <<" " <<Q;

    for (int i=0; i<Q; ++i)
    {
      string query;
      testcase >> query;
      cout <<  query;
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
