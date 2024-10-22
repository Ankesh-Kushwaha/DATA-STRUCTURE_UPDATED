#include <iostream>
using namespace std;

int fact(int n){
   //base case 
   if(n==1){
    return 1;
   }

   //recursive call;
   return n*fact(n-1);
}

int main(){
  int n;
  cout<<"enter the number to calculate the factorial:"<<endl;
  cin>>n;
  int ans=fact(n);
  cout<<ans<<endl;
  return 0;
}