#include <iostream>
#include <cmath>
using namespace std;

int fact(int n){
  int ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*i;
  }
  return ans;
}

bool isprime(int n){
   bool prime=true;
   if(n==1){
    prime=false;
    return prime;
   }

   for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      prime=false;
    }

   }
   return prime;
}

int combination(int n,int r){
  return (fact(n))/(fact(r)*fact(n-r));
}
 
int prime_in_range(int n,int m){
 int result=0;
 for(int i=n;i<=m;i++){
  if(isprime(i)==true){
    cout<<i<<" "<<endl;
    result++;
  }
  }
   return result;
}

 int main(){
  // int n,r;
  // cout<<"enter the value of n and r"<<endl;
  // cin>>n>>r;
  // int ans=combination(n,r);
  // cout<<"required combination are:"<<ans<<endl;
  int n,m;
  cout<<"enter the starting range:"<<endl;
  cin>>n;
  cout<<"enter the ending range:"<<endl;
  cin>>m;
   
   int ans=prime_in_range(n,m);
   cout<<"total prime number between "<<n<<" and "<<m<<" is: "<<ans<<endl;

  return 0;
 }