#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector< vector<int> > arr(6,vector<int>(6));

int hour_glass_sum(int x, int y)
{
  int sum=0;

  // no checks as we are in sandbox
 sum += arr[x][y] + arr[x][y+1] + arr[x][y+2] +
          arr[x+1][y+1] +
              arr[x+2][y] + arr[x+2][y+1] + arr[x+2][y+2];
  //debug
  //printf("DEBIG(%d):%d %d %d\n",y, arr[x][y], arr[x][y+1], arr[x][y+2]);
  return sum;
}

int main(){
    // defos
    int max=-99;

    // filling in array
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    //checking all hour glasses
    for (int i=0; i<=3; i++)
     for (int j=0; j<=3; j++)
       {
        int temp= hour_glass_sum(i,j);
        if (temp>max)
            max=temp;
       }
    printf("%i", max);
    return 0;
}
