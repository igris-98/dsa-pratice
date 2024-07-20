#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int,int> mp = {};
  int n = nums.size();

  for(int i= 0; i < n; i++){
    int diff = target - nums[i];
    if(mp.count(diff)){
      return {mp[diff], i};
    }
    mp[nums[i]] = i;
  }
  
  return {};
}
int main(int argc, char *argv[]) {
  vector<int>nums = {2,7,11,15};
  int target = 9;
  for (auto it: twoSum(nums,target)){
    cout << it << endl;
  }
  return 0;
}
