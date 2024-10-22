#include <iostream>
using namespace std;
int friendspairing(int n){
  //base case 
  if(n==1 ||n==2){
    return n;
  }
  return friendspairing(n-1)+(n-1)*friendspairing(n-2);
}
int main(){
 int n;
 cout<<"enter the value of n:"<<endl;
 cin>>n;
 cout<<friendspairing(n)<<endl;
  return 0;
}
