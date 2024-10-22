#include <iostream>
#include <string>
#include <queue>
using namespace std;


class heap{
 vector<int> vec;
 public:

 void push(int val){
   vec.push_back(val);

   //fixing the heap;
   int child_idx=vec.size()-1;
   int parent_idx=(child_idx-1)/2;
   while(parent_idx>=0 && vec[child_idx] >vec[parent_idx] ){
     swap(vec[child_idx],vec[parent_idx]);
     child_idx=parent_idx;
     parent_idx=(child_idx-1)/2;
   }
 } 
 
 void heapify(int i){ //parentidx=i
 if(i>vec.size()){
  return ;
 }
  int left=2*i+1;
  int right=2*i+2;

  int maxIdx=i;

  if(left<vec.size() && vec[left]>vec[maxIdx]){
    maxIdx=left;
  }

  if(right<vec.size() && vec[right]>vec[maxIdx]){
      maxIdx=right;
  }
  
  swap(vec[i],vec[maxIdx]);
  if(maxIdx!=i){
    heapify(maxIdx);
  }

 }
 void pop(){
  //swap root and leaf
  swap(vec[0],vec[vec.size()-1]);
  //delete the last node;
  vec.pop_back();

  //rearrange the heap
  heapify(0);
 }

 int top(){
  return vec[0];
 }

 bool isempty(){
   return vec.size()==0;
 }
};

class student{
  public:
  string name;
  int marks;

  student(string name,int marks){
    this->name=name;
    this->marks=marks;
  }

  bool operator < (const student &obj) const{
      return this->marks > obj.marks;
  }
};

int main(){
priority_queue<student>pq;
pq.push(student("ayush",99));
pq.push(student("ankesh",100));
pq.push(student("raghav",55));
pq.push(student("archit",88));

while(!pq.empty()){
  cout<<"name: "<<pq.top().name<<" and marks : "<<pq.top().marks<<endl;
  pq.pop();

}
  return 0;
}