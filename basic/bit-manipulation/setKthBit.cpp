#include <bits/stdc++.h>

using namespace std;
int setKthBit(int num, int k){
  return (num | (1 << k));
}

int main (int argc, char *argv[]) {
  
  int number, k;
  cin >> number >> k;

  cout << setKthBit(number, k) << endl;

  return 0;
}
