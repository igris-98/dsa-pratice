// leetcode- 1207

#include <bits/stdc++.h>

using namespace std;

bool uniqueOccurrence(vector<int> &arr){
  unordered_map<int, int> hash;
  for(int i =0; i < arr.size(); i++){
      hash[arr[i]]++;
  }
  set<int> unique;
  for(auto it : hash){
      unique.insert(it.second);
  }

  return unique.size() == hash.size();
}

int main (int argc, char *argv[]) {
  // vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
  vector<int> arr = {3,5,-2,-3,-6,-6};
  cout << uniqueOccurrence(arr) << endl;
  
  return 0;
}
