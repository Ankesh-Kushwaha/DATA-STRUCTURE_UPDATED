#include  <iostream>
using namespace std;
void even_odd(int n){
  if(n%2==0){
    cout<<"entered number is even"<<endl;
  }
  else{
    cout<<"entered number is odd"<<endl;
  }
}

int main(){
  int n;
  cout<<"enter the number:"<<endl;
  cin>>n;
  even_odd(n);
}