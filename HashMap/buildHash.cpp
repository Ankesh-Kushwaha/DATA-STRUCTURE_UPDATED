#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class Hashtable {
    int totalsize;
    int currsize;
    Node** table;

    int HashFunction(string key) {
        int idx = 0;
        //int p = 1;
        for (int i = 0; i < key.size(); i++) {
          idx=(key[i])%totalsize;
        }
        return idx;
    }

    void rehash() {
        Node** oldtable = table;
        int oldsize = totalsize;

        totalsize = 2 * totalsize;
        table = new Node*[totalsize];

        for (int i = 0; i < totalsize; i++) {
            table[i] = NULL;
        }

        currsize = 0;
        for (int i = 0; i < oldsize; i++) {
            Node* temp = oldtable[i];
            while (temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldtable[i] != NULL) {
                delete oldtable[i];
            }
        }

        delete[] oldtable;
    }

public:
    Hashtable(int size = 5) {
        totalsize = size;
        currsize = 0;

        table = new Node*[totalsize];

        for (int i = 0; i < totalsize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = HashFunction(key);

        Node* newHead = new Node(key, val);

        newHead->next = table[idx];
        table[idx] = newHead;
        currsize++;

        double lambda = currsize / (double)totalsize;
        if (lambda > 1) {
            rehash();
        }
    }

    bool exist(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(string key) {
        int idx=HashFunction(key);
        Node* temp=table[idx];
        Node* prev=temp;

        while(temp!=NULL){
          if(temp->key==key){
              
              if(temp==prev){
                table[idx]=temp->next;
              }
              else{
                prev->next=temp->next;
              }
              break;
          }

          prev=temp;
          temp=temp->next;
        }
    }

    void print(){

      for(int i=0;i<totalsize;i++){
        cout<<"idx :"<<i;
        Node* temp=table[i];
        while(temp!=NULL){
          cout<<"("<<temp->key<<","<<temp->value<<")"<<"->";
          temp=temp->next;
        }
        cout<<endl;
      }
    }
};

int main() {
    Hashtable ht;

    ht.insert("India", 150);
    ht.insert("china", 150);
    ht.insert("UK", 50);
    ht.insert("US", 60);
    ht.insert("nepal", 10);

    // if (ht.exist("nepal")) {
    //     cout << "population of nepal is: " << ht.search("nepal") << endl;
    // }
    ht.print();
    cout<<endl;
    ht.remove("nepal");
    ht.remove("china");
    ht.print();

    return 0;
}
