#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

// O(log n)
int count_digit(int number) {
  int count = 0;
  while (number) {
    count++;
    number = number / 10;
  }
  return count;
}
// O(1)
int optimal_count_digit(int number) { return int(log10(number) + 1); }

// O(log n)
int sum_of_digit(int number) {
  int sum = 0;
  while (number) {
    int digit = number % 10;
    sum = sum + digit;
    number = number / 10;
  }
  return sum;
}

// O(log n)
int reverse_number(int number) {
  int reverse = 0;
  while (number) {
    int digit = number % 10;
    reverse = digit + reverse * 10;
    number = number / 10;
  }
  return reverse;
}

// O(log n)
bool is_palindrome(int number) {
  int reverse = reverse_number(number);
  if (reverse == number)
    return true;
  return false;
}

// O(n)
bool is_palindrome_string(string str, int start, int end) {
  if(start >= end) return true;
  if(str[start] != str[end]) return false;
  return is_palindrome_string(str,start + 1, end - 1);
}

// O(log n)
bool is_armstrong(int number) {
  int total_multiplication = 0;
  int total_length = count_digit(number);
  int duplicateNumber = number;
  while (duplicateNumber) {
    int digit = duplicateNumber % 10;
    int cube = pow(digit, total_length);
    total_multiplication = total_multiplication + cube;
    duplicateNumber = duplicateNumber / 10;
  }
  if (total_multiplication == number)
    return true;
  return false;
}

// T(n) = O(n) & S(n) = O(n)
int *all_divisors(int number, int &size) {
  int *divisors = new int[number];
  int count = 0;
  for (int i = 1; i <= number; i++) {
    if (number % i == 0) {
      divisors[count++] = i;
    }
  }
  size = count;
  return divisors;
}

// T(n) = O(sqrt(n)) & S(n) = O(2 * sqrt(n))
vector<int> optimal_all_divisor(int number) {
  vector<int> divisors;
  for (int i = 1; i <= sqrt(number); i++) {
    if (number % i == 0) {
      divisors.push_back(i);

      // Add the counterpart divisor
      // if it's different from i
      if (i != number / i) {
        // Add the counterpart
        // divisor to the list
        divisors.push_back(number / i);
      }
    }
  }
  return divisors;
}

// O(n)
bool is_prime_no(int number) {
  if (number == 1)
    return true;
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

// O(sqrt(n))
bool is_prime_no_optimal(int number) {
  if (number == 1 && number == 2)
    return true;
  for (int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

// O(min(n1,n2)) -> O(n)
int gcd_brute_force(int num1, int num2) {
  int minNumber, gcd = 1;
  if (num1 < num2) {
    minNumber = num1;
  } else {
    minNumber = num2;
  }
  for (int i = 1; i <= minNumber; i++) {
    if(num1 % i == 0 && num2 % i == 0){
      gcd = i;
    }
  }
  return gcd;
}

int main(int argc, char *argv[]) {
  long long int number;
  // int number2;
  // cout << "Enter two numbers : ";
  cin >> number;
  // cin >> number2;

  // cout << "Total digits are " << count_digit(number) << " in " << number <<
  // endl;

  // cout << "Total digits are " << optimal_count_digit(number) << " in " <<
  // number << endl;

  // cout << "Sum of digits : " << sum_of_digit(number) << endl;

  cout << "Reverse Number : " << reverse_number(number) << endl;

  /* if(is_palindrome(number)){
    cout<< number << " is palindrome" << endl;
  } else {
    cout<< number << " is not palindrome" << endl;
  } */

  /* if(is_armstrong(number)){
    cout<< number << " is armstrong" << endl;
  } else {
    cout<< number << " is not armstrong" << endl;
  } */

  /* int size, *divisors;
  divisors = all_divisors(number, size);
  cout << "Divisors of " << number << " are: ";
  for (int i = 0; i < size; i++) {
      cout << divisors[i] << " ";
  }
  cout << std::endl;

  delete[] divisors; */

  /* vector<int> divisors;
  divisors = optimal_all_divisor(number);
  cout << "Divisors of " << number << " are: ";
  for (int divisor : divisors) {
      cout << divisor << " ";
  }
  cout << endl; */

  /* if(is_prime_no_optimal(number)){
    cout<< number << " is prime no." << endl;
  } else {
    cout<< number << " is not prime no." << endl;
  } */

  // cout << gcd_brute_force(number, number2) << endl;
  
  // string str;
  // cin >> str;
  // cout << is_palindrome_string(str, 0, str.length() - 1) << endl;
  return 0;
}
