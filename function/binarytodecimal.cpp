#include <iostream>
using namespace std;
void binTodecimal(int binNum){
  int decimal=0;
  int power=1;
  while(binNum!=0){
    int r=binNum%10;
     decimal=r*power;
     power=2*power;
     binNum=binNum/10;
  }
  cout<<"required decimal number is:"<<decimal<<endl;
}

int main(){
  int n;
  cout<<"enter the binary digit:"<<endl;
  cin>>n;
 
  binTodecimal(n);
  
  return 0;
}