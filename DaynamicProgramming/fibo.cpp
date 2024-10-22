#include<iostream>
#include<vector>
using namespace std;
int fibo(int n){
 if(n==0|| n==1){
  return n;
 }

 return fibo(n-1)+fibo(n-2);
}

int fiboDP(int n,vector<int> &f){
if(n==0 || n==1){ //memoization
  return n;
}

if(f[n]!=-1){
  return f[n];
}
 f[n]=fiboDP(n-1,f)+fiboDP(n-2,f);
 return f[n];
}

int fiboTabu(int n){
 vector<int> f(n+1,0); //Tabulation
 f[0]=0;
 f[1]=1;
 for(int i=2;i<=n;i++){
  f[i]=f[i-1]+f[i-2];
 }
 return f[n];
}

int main(){
  int n=71;
  //vector<int> f(n+1,-1);
  //cout<<fiboDP(n,f)<<endl;
  cout<<fiboTabu(n)<<endl;
  return 0;
}