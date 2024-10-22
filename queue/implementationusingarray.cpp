#include <iostream>
using namespace std;
class Queue{
  int *arr;
  int capacity;
  int curr_size;

  int f,r;

  public:
   Queue(int capacity){
      this->capacity=capacity;
      arr=new int[capacity];
      curr_size=0;

      f=0;
      r=-1;
   }

   void push(int data){
    if(curr_size==capacity){
      cout<<"QUEUE IS FULL"<<endl;
      return ;
    }
      r=(r+1)%capacity;
      arr[r]=data;
      curr_size++;
   }

   void pop(){
    if(empty()){
     cout<<"queue is empty:"<<endl;
     return;
    }
    f=(f+1)%capacity;
    curr_size--;
   }

   int front(){
    if(empty()){
      return -1;
    }
        return arr[f];
   }

   bool empty(){
     return curr_size==0;
   }

   void rear(){
    cout<<arr[r]<<endl;
   }
};

int main(){
  Queue q(6);
  for(int i=1;i<=7;i++){
    q.push(i);
  }

  cout<<q.front()<<endl;
  q.pop();
  q.push(7);
  cout<<q.front()<<endl;
  q.rear();
  return 0;
}