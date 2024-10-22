#include <iostream>
using namespace std;

class Node{
public:
  int data ;
  Node* next;
  Node(int val){
    data = val;
    next = NULL;
  }

  ~Node(){
    if (next != NULL) {
      delete next;
      next = NULL;
    }
  }
};

class List{
  Node* head;
  Node* tail;
public:
  List(){
    head = NULL;
    tail = NULL;
  }

  ~List(){
    if (head != NULL) {
      delete head;
      head = NULL;
    }
  }

public:
  void push_front(int val){
    Node* newNode = new Node(val); // dynamic allocation;
    
    if (head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }

  void push_back(int val){
    Node* newNode = new Node(val);
    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode; 
    }
  }

  void insert(int val, int pos){
    if (pos == 0) {
      push_front(val);
      return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
      if (temp == NULL) {
        cout << "Position is invalid" << endl;
        delete newNode;
        return;
      }
      temp = temp->next;
    }

    if (temp == NULL) {
      cout << "Position is invalid" << endl;
      delete newNode;
      return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == NULL) {
      tail = newNode;
    }
  }

  void printList(){
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void pop_front(){
    if (head == NULL) {
      cout << "Linked list is empty:" << endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    if (head == NULL) {
      tail = NULL;
    }
  }

  void pop_back(){
    if (head == NULL) {
      cout << "Linked list is empty:" << endl;
      return;
    }
    if (head->next == NULL) { // only one node in the list
      delete head;
      head = tail = NULL;
      return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
  }

  int search(int key){
    Node* temp=head;
    int idx=0;
    while(temp!=NULL){
       if(temp->data==key){
        return idx;
       }
       temp=temp->next;
       idx++;
    }
    return -1;
  }
  
int helper(Node* temp,int key){
  // base case
   if(temp==NULL){
    return -1;
   }
    if(temp->data==key){
      return 0;
    }

   int idx= helper(temp->next,key);
   if(idx==-1){
    return -1;
   }
   else{
    return idx+1;
   }
}

int  searchRec(int key){
  return helper(head,key);
}

void reverse(){
  Node* curr=head;
  Node* prev=NULL;
  while(curr!=NULL){
    Node* next=curr->next;
    curr->next=prev;

    //updations;
    prev=curr;
    curr=next;
  }
  head=prev;
}
};

int main(){
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList();

  ll.push_back(4);
  ll.push_back(5);
  ll.insert(100, 2);
  ll.printList();

  ll.insert(500, 6);
  ll.printList();

  ll.pop_front();
  ll.pop_back();
  ll.printList();
  cout<<endl;
  cout<<ll.searchRec(5)<<endl;

  cout<<endl;
  ll.reverse();
  ll.printList();
  return 0;
}
