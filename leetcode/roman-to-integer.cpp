#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int romanToInt(string str) {
  unordered_map<int,int> roman_mapping;
  roman_mapping['I'] = 1;
  roman_mapping['V'] = 5;
  roman_mapping['X'] = 10;
  roman_mapping['L'] = 50;
  roman_mapping['C'] = 100;
  roman_mapping['D'] = 500;
  roman_mapping['M'] = 1000;

  int sum = 0;
  int size = str.length();

  for (int i = 0; i < size;i++) {
    if(roman_mapping[str[i]] < roman_mapping[str[i+1]]){
      sum -= roman_mapping[str[i]];
    } else {
      sum += roman_mapping[str[i]];
    }
  }
  return sum; 
}

int main(int argc, char *argv[]) {
  string str = "III", str1 = "LVIII", str2 = "MCMXCIV";
  cout << romanToInt(str) << endl;
  cout << romanToInt(str1) << endl;
  cout << romanToInt(str2) << endl;
  return 0;
}
