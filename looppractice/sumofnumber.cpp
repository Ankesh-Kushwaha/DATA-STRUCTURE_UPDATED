#include <iostream>
using namespace std;
int main(){
  int n,sum=0;
  cout<<"enter the number of which sum is required"<<endl;
  cin>>n;
  while(n!=0){
    int r=n%10;
    sum+=r;
    n=n/10;
  }
  cout<<"required sum of given number is :"<<sum<<endl;
  return 0;
}