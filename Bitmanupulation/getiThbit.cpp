#include <iostream>
using namespace std;

int getith_bit(int num,int pos){
   int bit_mask=1<<pos;
  if(!(num & bit_mask)){
    return 1;
  }
  else{
   return 0;
  }
}

int setIthbit(int num,int pos){
  int bit_mask=1<<pos;
  return (num|bit_mask);
}

int clearIthbit(int num,int pos){
  int bit_mask=~(1<<pos);
  return (num & bit_mask);
}

int main(){
  int num,pos;
  cout<<"enter the num"<<endl;
  cin>>num;
  cout<<"enter the position of required bit:"<<endl;
  cin>>pos;
 // cout<<setIthbit(num,pos);
 cout<<clearIthbit(num,pos)<<endl;
  return 0;

}