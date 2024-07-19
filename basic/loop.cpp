#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int arr[5] = {1,2,3,4,5}, str_len;
  string str = "Igris";
  str_len = str.length();

  for (int i = 0; i < 5 ; i++) {
    cout << arr[i] << " ";
  }
  cout<< endl;

  int j=0;
  while(j < str_len){
    cout << str[j];
    j++;
  }
  cout<< endl;

  return 0;
}
