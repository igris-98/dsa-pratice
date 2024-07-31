#include <bits/stdc++.h>

using namespace std;
void swapTwoNumber(int &a, int &b){
  a = a ^ b;
  b = a ^ b;  // (a ^ b) ^ b = a;
  a = a ^ b; // (a ^ b) ^ a = b; 
}

// T(n) = O(1) lot faster than swapping using temp variable;
int main (int argc, char *argv[]) {
  
  int a, b;
  cin >> a >> b;

  cout << "a : " << a << " b : " << b << endl;
  cout << "After swap number " << endl;
  swapTwoNumber(a,b);
  cout << "a : " << a << " b : " << b << endl;
  return 0;
}
