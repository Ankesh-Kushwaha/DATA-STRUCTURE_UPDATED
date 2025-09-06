#include<iostream>
#include<algorithm>>
#include<vector>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n;i++){
      cin>> arr[i];
    }

    vector<long long> copy = arr;
    sort(copy.begin(), copy.end());

    if(arr==copy || k>1) {
      cout << "YES"<<endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}