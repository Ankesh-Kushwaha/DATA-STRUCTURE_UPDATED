#include <iostream>
#include <math.h>
using namespace std;
int count_digit(int n){
  int digit=0;
  while(n!=0){
     n%10;
     digit++;
     n=n/10;
  }
  return digit;
}
int main(){
  int n,new_sum=0;
  cout<<"enter the number to check it is armstrong or not:"<<endl;
  cin>>n;
    int m=n;
  int digit=count_digit(n);
  while(n!=0){
    int r=n%10;
    new_sum+=pow(r,digit);
    n=n/10;
  }
  if(m==new_sum){
    cout<<"the entered number is armstrong"<<endl;
  }
  else{
    cout<<"entered number is not a armstrong"<<endl;
  }
  return 0;
}