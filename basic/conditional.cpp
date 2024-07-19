#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int age, day;

  cout << "Enter age:";
  cin >> age;

  cout << "Enter Day (1-7): ";
  cin >> day;

  if (age < 18) {
    cout << "Not an adult" << endl;
  } else {
    cout << "An adult" << endl;
  }

  switch (day) {
    case 1: {
      cout << "Monday" << endl;
      break; // if don't use break after matching case all the below cases are also execute.
    }
    case 2: {
      cout << "Tuesday" << endl;
      break;
    }
    case 3: {
      cout << "Wednesday" << endl;
      break;
    }
    case 4: {
      cout << "Thurday" << endl;
      break;
    }
    case 5: {
      cout << "Friday" << endl;
      break;
    }
    case 6: {
      cout << "Saturday" << endl;
      break;
    }
    case 7: {
      cout << "Sunday" << endl;
      break;
    }
    default: {
      cout << "Not a valid no." << endl;
      break;
    }
  }

  return 0;
}
