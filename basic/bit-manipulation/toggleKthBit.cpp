#include <bits/stdc++.h>

using namespace std;
int toggleKthBit(int num, int k){
  return (num ^ (1 << k));
}

int main (int argc, char *argv[]) {
  
  int number, k;
  cin >> number >> k;

  cout << toggleKthBit(number, k) << endl;

  return 0;
}
