#include <iostream>
using namespace std;

void binary_string(int n,int lastplace,string ans){
    
    //base case
    if(n==0){
      cout<<ans<<endl;
      return ;
    }

    if(lastplace!=1){
       binary_string(n-1,0,ans+'0');
       binary_string(n-1,1,ans+'1');
    }
    else{
      binary_string(n-1,0,ans+'0');
    }
}

int main(){
  int n;
  cout<<"enter the value of n:"<<endl;
  cin>>n;
  string ans="";
  binary_string(n,0,ans);
  return 0;
}