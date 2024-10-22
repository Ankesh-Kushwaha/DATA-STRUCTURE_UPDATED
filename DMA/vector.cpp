#include <iostream>
#include<vector>
using namespace std;
int main(){
// vector<int>arr(5,-1);
//  cout<<arr.size()<<endl;
//  for(int i=0;i<arr.size();i++){
//   cout<<arr[i]<<" ";
//  }

  vector<int>v1={1,2,3,4};
  cout<<"size of v1 is:"<<v1.size()<<endl;
  cout<<"capacity of v1:"<<v1.capacity()<<endl;
  v1.push_back(5);
  cout<<"size of v1 is:"<<v1.size()<<endl;
  cout<<"capacity of v1:"<<v1.capacity()<<endl;
  return 0;
}
