#include <iostream>
using namespace std;
int main(){
  int n,sum=0;
  cout<<"enter the number:"<<endl;
  cin>>n;
  while(n!=0){
   int r=n%10;
   if(r%2!=0){
    sum+=r;
   }
   n=n/10;
  }

  cout<<"required sum of odd digits are:"<<sum<<endl;
  return 0;
}