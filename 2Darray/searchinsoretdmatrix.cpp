#include <iostream>
using namespace std;

void binary_search(int arr[][4],int start,int end,int key){
  bool ans=false;
  while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[start][mid]==key){
      ans=true;
      break;
    }
    else if(arr[start][mid]<key){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
}

void search_matrix1(int arr[][4], int n, int m, int key) {
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == key) {
                ans = true;
                break; // Break out of the inner loop
            }
        }
        if (ans) {
            break; // Break out of the outer loop if the key is found
        }
    }
    if (ans) {
        cout << "Key is present." << endl;
    } else {
        cout << "Key is not present." << endl;
    }
}

int main() {
    int arr[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    search_matrix1(arr, 4, 4,100);
    return 0;
}
