#include <iostream>
#include<string.h>
using namespace std;

void getreverse(char ch[],int n){
  int start=0;
  int end=n-1;
  while(start<end){
    swap(ch[end--],ch[start++]);
  }
}

int main(){
  char ch[]="ankeshkushwaha";
  getreverse(ch,strlen(ch));
  cout<<ch<<endl;
  return 0;
}