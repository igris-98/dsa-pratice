#include <bits/stdc++.h>

using namespace std;
int clearKthBit(int num, int k){
  return (num & ~(1 << k));
}

int main (int argc, char *argv[]) {
  
  int number, k;
  cin >> number >> k;

  cout << clearKthBit(number, k) << endl;

  return 0;
}
