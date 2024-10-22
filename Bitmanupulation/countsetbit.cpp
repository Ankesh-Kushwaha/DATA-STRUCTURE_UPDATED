#include <iostream>
using namespace std;
int countBit(int num){
   int count=0;
   while(num>0){
    int lastdigit=num&1;
    count+=lastdigit;
    num=num>>1;
   }
   return count;
}
int main(){
  int num;
  cout<<"enter the number"<<endl;
  cin>>num;
  cout<<countBit(num)<<endl;
}