#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// O(log n)
string convertDecimalToBinary(int num) {
  string binary = "";
  while (num != 0) {
    if (num % 2 == 1) {
      binary += '1';
    } else {
      binary += '0';
    }
    num = num / 2;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}

// O(n) : n-> string size;
int covertBinaryToDecimal(string binary) {
  int length = binary.size();
  int decimal = 0;
  /* for (int i = 0; i < binary.size(); i++) {
    int bit;
    if (binary[i] == '1') {
      bit = 1;
    } else {
      bit = 0;
    }
    decimal += pow(2, length - i - 1) * bit;
  } */

  int power = 1; // 2^0
  for (int i = length - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += power;
    }
    power *= 2;
  }

  return decimal;
}

int main(int argc, char *argv[]) {
  int num; // always decimal number
  cin >> num;

  string binary = convertDecimalToBinary(num);
  cout << "-----" << endl;
  cout << "decimal -> binary" << endl;
  cout << binary << endl;

  cout << "-----" << endl;
  cout << "binary -> decimal" << endl;
  cout << covertBinaryToDecimal(binary) << endl;
  return 0;
}
