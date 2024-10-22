#include <iostream>
using namespace std;
int pow(int x,int n){
  //base case;
  if(n==0){
    return 1;
  }

  int half_power=pow(x,n/2);
  int square_power=half_power*half_power;

  if(n%2!=0){
    return x*square_power;
  }
  return square_power;
}

int main(){
  int x,n;
  cout<<"enter the value of base:"<<endl;
  cin>>x;
  cout<<"enter the value of power:"<<endl;
  cin>>n;

  int ans=pow(x,n);
  cout<<ans<<endl;
  return 0;
}