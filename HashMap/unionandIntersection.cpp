#include<iostream>
#include<vector>
#include<set>
using namespace std;

void getUnion(vector<int> arr1,vector<int> arr2){
  set<int> s;
  for(int el:arr1){
    s.insert(el);
  }

  for(int el:arr2){
    s.insert(el);
  }

  for(int i :s){
    cout<<i<<" ";
  }
  cout<<endl;
}

void getIntersection(vector<int> arr1,vector<int> arr2){
   set<int>s;

   for(int i:arr1){
    s.insert(i);
   }

   for(int i:arr2){
    if(s.find(i)!=s.end()){
      cout<<i<<" ";
      s.erase(i);
    }
   }
   cout<<endl;
}
int main(){
  vector<int>arr1={6,3,9,2,9,4};
  vector<int> arr2={7,3,9};
  getUnion(arr1,arr2);
  getIntersection(arr1,arr2);
  return 0;
}