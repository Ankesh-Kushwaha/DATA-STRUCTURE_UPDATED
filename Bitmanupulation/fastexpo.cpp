#include <iostream>
using namespace std;
int fastExpo(int base ,int power){
  int ans=1;
  while(power>0){
     int lastdigit=power&1;
     if(lastdigit){
      ans=ans*base;
     }              //Time Complexity=O(logn); 

     base=base*base;
     power=power>>1;
  }
  cout<<ans<<endl;
}

int main(){
  int base,power;
  cout<<"enter the base:"<<endl;
  cin>>base;
  cout<<"enter the power:"<<endl;
  cin>>power;
  fastExpo(base,power);
  return 0;
}