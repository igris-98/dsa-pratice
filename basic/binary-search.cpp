#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int binarySearch(int arr[],int start, int end, int key){
  if(start > end) return -1;
  int mid = ceil((start + end) / 2);
  // prevent overflow INT_MAX
  // int mid = low + (high - low) / 2;

  if(key == arr[mid]) return mid;
  else if(key < arr[mid]) return binarySearch(arr, start, mid-1, key);
  else return binarySearch(arr, mid+1, end, key);
}

int lowerbound(int arr[],int start, int end, int key){
  // smallest index arr[index] >= key
  if(start > end) return -1;
  int mid = ceil((start + end) / 2);

  if(key == arr[mid]) return mid;
  else if(key < arr[mid]) return binarySearch(arr, start, mid-1, key);
  else return binarySearch(arr, mid+1, end, key);
}

int upperbound(int arr[],int start, int end, int key){
  // smallest index arr[index] > key
  if(start > end) return -1;
  int mid = ceil((start + end) / 2);

  if(key <= arr[mid]) return mid;
  else if(key < arr[mid]) return binarySearch(arr, start, mid-1, key);
  else return binarySearch(arr, mid+1, end, key);
}


int main (int argc, char *argv[]) {
  int arr[5] = { 2,3,5,10,20};
  int start = 0, end = 5;

  cout << binarySearch(arr, start, end, 4) << endl;

  return 0;
}
