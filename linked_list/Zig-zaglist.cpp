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
public:
   Node* head;
   Node* tail;
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

  void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
Node* splitAtMid(Node* head){
  Node* slow=head;
  Node* fast=head;
  Node* prev=NULL;
  while(fast!=NULL && fast->next!=NULL){
    prev=slow;
    slow=slow->next;
    fast=fast->next->next;
  }

  if(prev!=NULL){
    prev->next=NULL;//splitting at middle;
  }
  return slow; //slow=rightHead
}

Node* reverse(Node* head){
  Node* curr=head;
  Node* prev=NULL;
  while(curr!=NULL){
    Node* next=curr->next;
    curr->next=prev;

    //updation;
    prev=curr;
    curr=next;
  }
  return prev;// head of reversed linked list;
}

Node* zigZag(Node* head){
  Node* righthead=splitAtMid(head);
  Node* rightheadrev=reverse(righthead);
  
  //alternate merging: 1st head=head, 2nd head=rightheadrev;
  Node* left=head;
  Node* right=rightheadrev;
  Node* tail=right;
  while(left!=NULL && right!=NULL){
    Node* nextleft=left->next;
    Node* nextright=right->next;

    //making connections;
    left->next=right;
    right->next=nextleft;
    tail=right;

    //updations 
    left=nextleft;
    right=nextright;
  }
  
  if(right!=NULL){
    tail->next=right;
  }

  return head;
}

int main(){
  List ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(5);
  //ll.push_back(6);
  ll.print(ll.head);
  zigZag(ll.head);
  ll.print(ll.head);
  return 0;
}