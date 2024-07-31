#include <bits/stdc++.h>

using namespace std;
bool isKthBitSet(int num, int k){
  return (num & (1 << k)) != 0 ;
}

int main (int argc, char *argv[]) {
  
  int number, k;
  cin >> number >> k;

  cout << isKthBitSet(number, k) << endl;

  return 0;
}
