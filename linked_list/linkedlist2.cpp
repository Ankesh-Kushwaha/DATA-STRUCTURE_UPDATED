#include <iostream>
using namespace std;

class Node{
public:
 int data;
 Node* next;

 Node(int val){
  data=val;
  next=NULL;
 }
};

class List{
   Node* head;
   Node* tail;
public:
  List(){
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
      head=newNode;
    }
  }

  void push_back(int val){
    Node* newNode=new Node(val);
    if(head==NULL){
      head=tail=newNode;
    }
    else{
      tail->next=newNode;
      tail=newNode;
    }
  }

  void print(){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
  }
 int getsize(){
   int n=0;
   Node* temp=head;
   while(temp!=NULL){
    temp=temp->next;
    n++;
   }
   return n;
 }

  void remove_nTh(int n){
    int size=getsize();
    Node *prev=head;
    for(int i=1;i<(size-n);i++){
      prev=prev->next;
    }
   
   Node* toDelete=prev->next;
   cout<<"going to delete the "<<toDelete->data<<endl;
    prev->next=prev->next->next;
  }

};
int main(){
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.push_back(4);
  ll.push_back(5);
  ll.push_back(6);
  ll.print();
  ll.remove_nTh(2);
  ll.print();
  return 0;
}