#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;

string toggleCase(string str){
  for(int i = 0; i < str.size(); i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] += 32;
    } else if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] -= 32;
    }
  }
  return str;
}

int main (int argc, char *argv[]) {
  // char char_string[] = {'H', 'e', 'l', 'l', 'o'}; // must be single quotes
  // char *str = "hello";


  // string are treated as character's array or iterable
  string word;
  // string line;

  cout << "Enter a String with cin: ";
  // cin get character till space.
  cin >> word;
  cout << word << endl;
  // cout << word[0] << endl;
  // cout << word.size() << endl;


  /* // To discard enter
  cin.ignore();

  cout << "Enter a String with getline: ";
  // getline get character till `/n or enter`.
  getline(cin, line);
  cout << line << endl; */


  cout << toggleCase(word) << endl;
  
  return 0;
}
