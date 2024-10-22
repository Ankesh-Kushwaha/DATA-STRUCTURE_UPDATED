#include <iostream>
#include<string.h>
using namespace std;
bool checkpalindrome(char ch[],int n){
   int start=0;
   int end=n-1;
   while(start<=end){
    if(ch[start++]==ch[end--]) return true;
   }
   return false;
}
int main(){
  char ch[]="ankesh";
  cout<<checkpalindrome(ch,strlen(ch))<<endl;
  return 0;
}