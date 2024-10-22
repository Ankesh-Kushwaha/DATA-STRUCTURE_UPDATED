#include<iostream>
#include<vector>
using namespace std;

int total_notes(vector<int> coins,int V){
  int n=coins.size();
  int ans=0;
    for(int i=n-1;i>=0 && V>0 ;i--){
      if(V>=coins[i]){
         cout<<"required Notes of "<<coins[i]<<":"<<ans<<endl; 
          ans+=V/coins[i]; //for finding the amount of notes
          V=V%coins[i];  //for finding the remainder left
      }
    }
    return ans;
}
int main(){
vector<int> coins={1,2,5,10,20,50,100,500,2000};
int V;
cout<<"enter the amount:"<<endl;
cin>>V;
 
 cout<<"The required amount of notes is :"<<total_notes(coins,V)<<endl;
  return 0;
}