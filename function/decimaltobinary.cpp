#include <iostream>
using namespace std;
void decTobin(int decNUm){
  int n=decNUm;
  int pow=1;//10^0 10^1 10^2.....
  long long binNum=0;
  while(n>0){
   int rem=n%2;
  binNum+=rem*pow;
  n=n/2;
  pow=pow*10;
  }
  cout<<"required binary number is:"<<binNum<<endl;
}
int main(){
   int n;
   cout<<"enter the decimal number"<<endl;
   cin>>n;
   decTobin(n);
  return 0;
}