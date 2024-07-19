#include <bits/stdc++.h>
using namespace std;

void box_pattern(int input, char type, bool isReverse){
  for(int row = 0; row < input; row++){
    for(int col = 0; col < input; col++){
      if(type == 'n'){
        if(isReverse) {
          cout << input - col << " ";
        } else {
          cout << col + 1 << " ";
        }
      } 
      if(type == 's'){
        cout << "* ";
      } 
    }
    cout << endl;
  }
}

void count_pattern(int input, char type, bool isReverse){
  int count = 0;
  for(int row = 0; row < input; row++){
    for(int col = 0; col < input; col++){
      if(type == 'n'){
        count = count + 1;
        cout << count << " ";
      } 
    }
    cout << endl;
  }
}

void stair_pattern(int input, char type, bool isReverse){
  if(!isReverse){
    for(int row = 0; row < input; row++){
      for(int col = 0; col < row; col++){
        if(type == 'n'){
          cout << col + 1 << " ";
        } 
        if(type == 's'){
          cout << "* ";
        } 
      }
      cout << endl;
    }
  } else {
    for(int row = 0; row < input; row++){
      for(int col = 0; col < input - row; col++){
        if(type == 'n'){
          cout << col + 1 << " ";
        } 
        if(type == 's'){
          cout << "* ";
        } 
      }
      cout << endl;
    }
  }
}

int main (int argc, char *argv[]) {
  int input;
  char type = 'n';
  bool isReverse = 0;
  cout << "Enter range : ";
  cin >> input;
  cout << "Enter type [ nubmer(n), star(s)] : ";
  cin >> type;
  cout << "Enter Reverse [0,1] : ";
  cin >> isReverse;
  // box_pattern(input, type, isReverse);
  // count_pattern(input, type, isReverse);
  stair_pattern(input, type, isReverse);
  
  return 0;
}
