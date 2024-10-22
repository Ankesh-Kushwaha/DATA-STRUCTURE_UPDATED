#include <iostream>
#include<string.h>
using namespace std;
int main(){
  // char ch[]={'a','b','c','d','e','\0'};
  // cout<<ch<<endl;//simply print the whole element of the array;
  // char work[]="hello";
  // cout<<strlen(work)<<endl; //it does not count the null character
  // cout<<work<<endl;
  // char work2[6]="hello"; //always keep size n+1 for null character;
  // cout<<work2<<endl;

  // char ch2[50]="Ankesh Kushwaha";//extra space may be store garbage value
  // cout<<ch2<<endl;
  
  char word[30];
  //cin>>word;
  cin.getline(word,30,'.');
  cout<<"your word is:"<<word<<endl;
  cout<<strlen(word)<<endl;
  return 0;
}