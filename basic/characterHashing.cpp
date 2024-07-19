#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main () {
  string str;
  cin >> str;

  //pre-computing
  int hash_arr[26] = {0}, size = str.size();
  for(int i=0; i< size;i++){
      hash_arr[str[i] - 'a']++;
  }

  int test;
  cin >> test;
  while(test--){
    char ch;
    cin >> ch;
    //fetching
    cout << hash_arr[ch - 'a'] << endl;
    // solve();
  }


  return 0;
}
  
