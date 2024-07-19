#include <bits/stdc++.h>
#include <utility>

using namespace std;

// T(n) = O(n); S(n) = O(n)
void n_times(int number){
  if(number > 0){
    cout << number << endl;
    n_times(number - 1);
  }
}

// T(n) = O(n); S(n) = O(n)
void n_times_reverse(int number){
  if(number > 0){
    n_times_reverse(number - 1);
    cout << number << endl;
  }
}

// T(n) = O(n); S(n) = O(n)
int sum_first_n_numbers(int number){
  if(number == 0){
    return 0;
  }
  return sum_first_n_numbers(number - 1) + number;
}

// T(n) = O(n); S(n) = O(n)
int factorial_recursive(int number){
  if(number == 1){
    return 1;
  }
  return factorial_recursive(number - 1) * number;
}

// T(n) = O(n); S(n) = O(n)
void reverse_array_recursive(int arr[], int start, int end){
  // TODO : try again after some time
  if(start < end){
    swap(arr[start], arr[end]);
    reverse_array_recursive(arr, start + 1, end - 1);
  }
}

// T(n) = O(2^n); S(n) = O(n)
int fibonacci(int number){
  if(number < 0) { return -1; };
  if(number <= 1){ 
    return number;
  }
  return fibonacci(number - 1) + fibonacci(number - 2);
}

void print_array(int arr[],int length){
  for(int i = 0; i < length; i++){
    cout << arr[i] << endl;
  }
}

int main (int argc, char *argv[]) {
  int number;
  cout << "Enter a Number: ";
  cin >> number;

  /* n_times(number);
  cout << "-----" << endl;
  n_times_reverse(number); */

  // cout << sum_first_n_numbers(5) << endl;
  
  // cout << factorial_recursive(5) << endl;

  /* int arr[5] = {1, 2, 3, 4, 5};
  print_array(arr, 5);
  reverse_array_recursive(arr,0,4);
  print_array(arr, 5); */

  cout << fibonacci(number) << endl;
  
  return 0;
}
