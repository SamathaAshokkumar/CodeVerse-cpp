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


/*
int main(){
    int t;
    cin >> t;
    int *arr=new int[t];
    //int result[t];
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n; 
        arr[a0]=n;
    }
*/

int main()
{
 vector<int> arr(5);
 int x=2;
 arr[x-1]+=2;
 arr[4]-=2;
 for(int i :arr)
 {
    cout<<i<<endl;
 }
 return 0;
}  
    
    
  