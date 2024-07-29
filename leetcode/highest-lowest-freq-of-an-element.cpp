#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main(int argc, char *argv[]) {
  int size;
  cin >> size;

  int arr[] = {10, 5, 10, 15, 10, 5};
  unordered_map<int, int> freq_of_number;
  // for(int i = 0; i< size; i++){
  //   cin >> arr[i];
  // }

  for (int i = 0; i < size; i++) {
    freq_of_number[arr[i]]++;
  }

  int maxFreq = INT_MIN, minFreq = INT_MAX;
  int maxEle = INT_MIN, minEle = INT_MAX;
  for (auto it : freq_of_number) {
    if (maxFreq < it.second) {
      maxEle = it.first;
      maxFreq = it.second;
    }
    if (minFreq > it.second) {
      minEle = it.first;
      minFreq = it.second;
    }
  }

  cout << maxEle << " " << minEle << endl;

  return 0;
}
