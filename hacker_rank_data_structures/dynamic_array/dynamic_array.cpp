#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//NB get rid of the below
class elements{
  vector <int> values;
};

class SeqList{
public:
  SeqList(int N);
  ElementAppend(int position, int value);
  int LastAnswer = 0;
  PrintSeqList();
private:
  int size_N;
  vector<elements> SeqListArray;
};

void PrintSeqList()
{
  int n=SeqListArray[position].elements.size();
  for (int i=0; i<n; ++i)
  {
    
  }
}

void ElementAppend(int position, int value)
{
  int new_node_size = SeqListArray[position].elements.size()+1;
  SeqListArray[position].elements.reserve(new_node_size);
  SeqListArray[position].elements[new_node_size] = value;
}


void SeqList::SeqList(int N)
{
  SeqListArray.reserve(N);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // declarations
    int N, Q;

    // Reading N(number of sequences) and Q(number of queries)
    cin >> N >> Q;

    //Looping through queries

    // Returning the result

    return 0;
}
