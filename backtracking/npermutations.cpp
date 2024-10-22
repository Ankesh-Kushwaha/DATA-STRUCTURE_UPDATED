#include <iostream>
#include<string>
using namespace std;
void permutation(string str,string ans){
    int n=str.size();
    //base case
    if(n==0){
      cout<<ans<<endl;
      return;
    }

    for(int i=0;i<n;i++){
       string next=str.substr(0,i)+str.substr(i+1,n-i-1);//deleting particular character from string;
       permutation(next,ans+str[i]);
    }
}
int main(){
  string str="abc";
  string ans="";
  permutation(str,ans);
  return 0;
}