#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="100";
    int i=0;
    int ans=0;
    int j=s.length()-1;
    while(i<=j){
        if(s[i]=='0'){
          i++;
        }
        else if(s[j]=='1'){
          j--;
        }
        else{
          if(s[i]=='1' && s[j]=='0'){
             swap(s[i],s[j]);
             ans++;
             i++;
             j--;
          }
        }
    }

    cout<<s<<endl;
    cout<<ans<<endl;
  return 0;
}