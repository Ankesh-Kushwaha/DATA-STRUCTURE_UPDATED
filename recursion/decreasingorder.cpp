#include <iostream>
using namespace std;

void order(int n){
  //base case 
  if(n==0){
    return;
  }
 
  cout<<n<<endl;
    order(n-1);
}
int main(){
  int n;
  cin>>n;
  order(n);
 return 0;
}