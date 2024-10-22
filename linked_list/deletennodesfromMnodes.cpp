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

  void print(){
    Node* temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
void deleteNode(Node* head, int m, int n) {
    Node* prev = head;
    while (prev != NULL) {
        // Skip m nodes
        for (int i = 1; i < m && prev != NULL; i++) {
            prev = prev->next;
        }
        // If we've reached the end of the list, break
        if (prev == NULL) {
            break;
        }
        
        // Start from the next node
        Node* curr = prev->next;
        // Skip n nodes
        for (int i = 1; i <= n && curr != NULL; i++) {
            Node* temp = curr;
            curr = curr->next;
            delete temp; // free the memory of the deleted node
        }

        // Reconnect the list
        prev->next = curr;
        // Move prev to the next node to continue the process
        prev = curr;
    }
}

int main(){
List ll;
for(int i=1;i<=10;i++){
  ll.push_back(i);
}
ll.print();
deleteNode(ll.head,3,2);
ll.print();
  return 0;
}