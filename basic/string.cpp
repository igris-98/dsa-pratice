#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
  // string are treated as character's array or iterable
  string word, line;

  cout << "Enter a String with cin: ";
  // cin get character till space.
  cin >> word;
  cout << word << endl;
  cout << word[0] << endl;
  cout << word.size() << endl;


  // To discard enter
  cin.ignore();

  cout << "Enter a String with getline: ";
  // getline get character till `/n or enter`.
  getline(cin, line);
  cout << line << endl;
  
  return 0;
}
