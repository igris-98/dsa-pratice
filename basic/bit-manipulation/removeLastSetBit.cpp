#include <bits/stdc++.h>

using namespace std;
int removeLastSetBit(int num){
  return (num & (num - 1));
}

int main (int argc, char *argv[]) {
  
  int number;
  cin >> number;

  cout << removeLastSetBit(number) << endl;

  return 0;
}
