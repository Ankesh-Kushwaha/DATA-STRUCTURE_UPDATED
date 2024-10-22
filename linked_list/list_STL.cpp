#include <iostream>
#include<list>
#include<iterator>
using namespace std;
void printList(list<int>ll){
 list<int>::iterator itr;
  for(itr=ll.begin();itr!=(ll.end());itr++){
  cout<<*itr<<"->";
  }
  cout<<"NULL"<<endl;
}

int main(){
  list<int> ll;//same as vector
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(8);
  ll.push_back(9);
  ll.push_back(70);
  printList(ll);
  cout<<ll.size()<<endl;
  cout<<"head="<<ll.front()<<endl;
  cout<<"tail="<<ll.back()<<endl;
  ll.pop_front();
  ll.pop_back();
  list<int>::iterator it;
  it=ll.end();
  ll.insert(it,10,3);
  printList(ll);
return 0;
}