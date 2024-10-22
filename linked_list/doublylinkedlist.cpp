#include<iostream>
using namespace std;

class Node{
 public: 
  int data;
  Node* next;
  Node* prev;
 Node(int val){
   data=val;
   next=prev=NULL;
 }
};

class doublyll{
  public:
  Node* head;
  Node* tail;
  doublyll(){
    head=NULL;
    tail=NULL;
  }

void push_front(int val){
   Node* newNode=new Node(val);

   if(head==NULL){
    head=tail=newNode;
   }
   else{
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
   }
}

 void printList(){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"<=>";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
 }

void pop_front(){
  Node* temp=head;
  head=head->next;
  if(head!=NULL){
    head->prev=NULL;
  }
  temp->next=NULL;
  delete temp;
  
}

};
int main(){
  doublyll dbll;
  dbll.push_front(5);
  dbll.push_front(4);
  dbll.push_front(3);
  dbll.push_front(2);
  dbll.push_front(1);
  dbll.printList();
  dbll.pop_front();
  dbll.printList();
  return 0;
}