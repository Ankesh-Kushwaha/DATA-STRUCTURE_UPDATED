#include <iostream>
using namespace std;

bool Powerof2(int num){
   if(!(num &(num-1))){
    return true;
   }
   else{
    return false;
   }
}
int main(){
  int num;
  cout<<"enter the number to check:"<<endl;
  cin>>num;
  cout<<Powerof2(num)<<endl;
  return 0;
}