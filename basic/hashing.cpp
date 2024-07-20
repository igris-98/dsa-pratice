#include <bits/stdc++.h>
#include <climits>
using namespace std;

void solve(){

}

// int a[]; // globally array can store upto 10^7 elements;
int main () {
  int n;
  cin >> n;
  int arr[n]; // locally array can store upto 10^6 elements;

  int max = INT_MIN;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(max < arr[i]){
      max = arr[i];
    }
  }

  //pre-computing
  int hash_arr[max+1] = {0};
  for(int i=0; i<n;i++){
      hash_arr[arr[i]]++;
  }

  int test;
  cin >> test;
  while(test--){
    int number;
    cin >> number;
    //fetching
    cout << hash_arr[number] << endl;
    // solve();
  }


  return 0;
}
  
