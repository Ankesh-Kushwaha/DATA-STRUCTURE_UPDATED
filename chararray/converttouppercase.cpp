#include <iostream>
#include<string.h>
using namespace std;
void toLowercase(char arr[],int n){
    for(int i=0;i<n;i++){
      char ch=arr[i];
       if(ch>='a' && ch<='z'){
        continue;
       }
       else{
        arr[i]=ch-'A'+'a';
       }
    }
}

void toUpper(char arr[],int n){
  for(int i=0;i<n;i++){
   char ch=arr[i];
   if(ch>='A' && ch<='Z'){
    continue;
   }
   else{
    arr[i]=ch-'a'+'A';
   }
  }
 
}
int main(){
  char word[50];
  cout<<"enter the string to convert"<<endl;
  cin.getline(word,50,'.');
  //toUpper(word,50);
   toLowercase(word,50);
  cout<<word<<endl;
  return 0;
}