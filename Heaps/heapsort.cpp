#include <iostream>
#include <vector>
using namespace std;

void heapify(int i,vector<int> &vec,int n){
  int left=2*i+1;
  int right=2*i+2;
  int maxIdx=i;
  if(left<n && vec[left]>vec[maxIdx]){
    maxIdx=left;
  }

  if(right<n && vec[right]>vec[maxIdx]){ //complexity=O(logn);
    maxIdx=right;
  }

  if(maxIdx!=i){
    swap(vec[i],vec[maxIdx]);
    heapify(maxIdx,vec,n);
  }
}

void heapSort(vector<int> &vec){
int n=vec.size();
//step:1 building heap sort;
for(int i=n/2-1;i>=0;i--){ //O{n};
   heapify(i,vec,n);
}

//step:2 sorting;
for(int i=n-1;i>=0;i--){  //O(n);
  swap(vec[0],vec[i]);
  heapify(0,vec,i);
}

}
int main(){
vector<int> vec={1,4,2,5,3}; //total complexity=O(n(logn));
heapSort(vec);
for(int i=0;i<vec.size();i++){
  cout<<vec[i]<<" ";
}
  return 0;
}