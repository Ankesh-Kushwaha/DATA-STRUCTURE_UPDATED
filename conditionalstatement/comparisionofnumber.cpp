#include <iostream>
using namespace std;
int main(){
  int number;
  cout<<"enter the number to check"<<endl;
  cin>>number;
  if(number>0){
    cout<<"number is positive"<<endl;
  }
  else if(number<0){
    cout<<"number is negative"<<endl;
  }
  else{
    cout<<"entered number is zero"<<endl;
  }
  return 0;
}