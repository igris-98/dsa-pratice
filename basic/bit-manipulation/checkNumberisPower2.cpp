#include <bits/stdc++.h>

using namespace std;
bool isPowerOf2(int num){
  return (num & (num - 1)) == 0;
}

int main (int argc, char *argv[]) {
  
  int number;
  cin >> number;

  cout << isPowerOf2(number) << endl;

  return 0;
}
