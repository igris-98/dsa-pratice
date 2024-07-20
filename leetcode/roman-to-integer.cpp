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

  for(int i = str.size(); i >= 0 ; i--){
    if (i != 0) {
      if(str[i] == 'V' && str[i-1] == 'I'){
        sum += 4;
        i--;
        continue;
      }
      if(str[i] == 'X' && str[i-1] == 'I'){
        sum += 9;
        i--;
        continue;
      }
      if(str[i] == 'L' && str[i-1] == 'X'){
        sum += 40;
        i--;
        continue;
      }
      if(str[i] == 'C' && str[i-1] == 'X'){
        sum += 90;
        i--;
        continue;
      }
      if(str[i] == 'D' && str[i-1] == 'C'){
        sum += 400;
        i--;
        continue;
      }
      if(str[i] == 'M' && str[i-1] == 'C'){
        sum += 900;
        i--;
        continue;
      }
    
    }
    sum += roman_mapping[str[i]];
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
