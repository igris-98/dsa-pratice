#include <bits/stdc++.h>
using namespace std;

/* 
// declaration 
return_type function_name(parameter1, parameter2){
  statements;
  return return_value;
}
// calling/ invoking
function_name(argument1, argument2); 
*/

//declaration on function
void pass_by_value(int num){
  cout<< "num before mutating in function : " << num << endl;
  num = 10;
  cout<< "num after mutating in function : " << num << endl;
}

void pass_by_reference(int &num){
  cout<< "num before mutating in function : " << num << endl;
  num = 10;
  cout<< "num after mutating in function : " << num << endl;
}

int main (int argc, char *argv[]) {
  int num = 5;
  cout << "-----PASS BY VALUE-----" << endl;
  cout<< "num berfore calling function : " << num << endl;
  // Calling the function
  pass_by_value(num);
  cout<< "num after calling function : " << num << endl;
  cout << "-----PASS BY VALUE-----" << endl;
  cout<< endl;

  cout << "-----PASS BY REFERENCE-----" << endl;
  cout<< "num berfore calling function : " << num << endl;
  // Calling the function
  pass_by_reference(num);
  cout<< "num after calling function : " << num << endl;
  cout << "-----PASS BY REFERENCE-----" << endl;
  cout<< endl;
  
  return 0;
}
