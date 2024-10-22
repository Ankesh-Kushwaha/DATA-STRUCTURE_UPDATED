#include <iostream>
using namespace std;
void UpdateIthbit(int num, int pos, int val) {
    num = num & ~(1 << pos); // Clear ith bit
    num = num | (val << pos); // Set the ith bit to `val`
    cout << num << endl; // Print the updated number
}

int main(){
  UpdateIthbit(7,2,0);
  return 0;
}