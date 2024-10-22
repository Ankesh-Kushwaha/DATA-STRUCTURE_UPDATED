#include <iostream>
#include<string>
using namespace std;

void removeDuplicate(string str,string ans,int i,int *map){
     int mapidx=(int)str[i]-'a'; //finding index of character;
     
     //base case
     if(i==str.length()){
        cout<<ans<<" ";
        return ;
     }
      
     if(map[mapidx]){ //duplicate
      removeDuplicate(str,ans,i+1,map);
     }
     else{ //not duplicate
         map[mapidx]=true;
         removeDuplicate(str,ans+str[i],i+1,map);
     }
}
int main(){
  string str="appnaacollege";
  string ans="";
  int map[26]={false};
  removeDuplicate(str,ans,0,map);
  return 0;
}