#include <iostream>
using namespace std;
void clearlastbit(int num,int pos){
  int bit_mask=~0<<pos;
  num=num & bit_mask;
  cout<<num<<endl; 
}
int main(){
  int num,pos;
  cout<<"enter the number:"<<endl;
  cin>>num;
  cout<<"enter the position:"<<endl;
  cin>>pos;
  clearlastbit(num,pos);
  return 0;
}