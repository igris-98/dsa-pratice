#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main () {
  int n;
  cin >> n;
  int arr[n];

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  //pre-computing
  map<int, int> mp;
  for(int i=0; i<n;i++){
      mp[arr[i]]++;
  }

  int test;
  cin >> test;
  while(test--){
    int number;
    cin >> number;
    //fetching
    cout << mp[number] << endl;
  }


  return 0;
}
  
