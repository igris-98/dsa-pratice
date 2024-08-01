#include <bits/stdc++.h>

using namespace std;
// O(log (start ^ end));
int minimumFlipToConvertNumber(int start , int goal){
  // number should be positive integer
  // range b/w 0 to 2^32
  int flipBits = start ^ goal;
  int count = 0;

  int lastIndex = 31; // 2^32 -> 0 based index
  for(int i = 0; i <= lastIndex; i++){
    if(flipBits & (1 << i)){
      count++;
    }
  }

  return count;
}

int main (int argc, char *argv[]) {
  int start , goal;
  cin >> start >> goal;

  cout << minimumFlipToConvertNumber(start, goal) << endl;
  
  return 0;
}
