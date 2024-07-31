#include <bits/stdc++.h>

using namespace std;

int countSetBits(int num) {

  // return __builtin_popcount(num);

  int count = 0;
  while (num > 0) {
    // num & 1 == num % 2 == 1;
    if (num & 1) {
      count++;
    }
    // num >> 1 == num / 2;
    num = num >> 1;
  }

  return count;
}

int countSetBits2(int num) {

  // return __builtin_popcount(num);

  int count = 0;
  while (num != 0) {
      count++;
    num = num & (num - 1);
  }

  return count;
}

int main(int argc, char *argv[]) {

  int number;
  cin >> number;

  // cout << countSetBits(number) << endl;
  cout << countSetBits2(number) << endl;

  return 0;
}
