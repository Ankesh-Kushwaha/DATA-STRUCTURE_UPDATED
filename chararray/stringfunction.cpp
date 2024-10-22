#include <iostream>
#include<cstring>
using namespace std;
int main(){
  char str1[100];
  char str2[]="becomes a best coder";
  strcpy(str1,"ankesh kushwaha "); //copy string from one array or string to another charcter array;
  //strcpy(str1,str2);
  //cout<<str1<<endl;
  strcat(str1,str2); //add two strings;
  cout<<str1<<endl;

  cout<<strcmp(str2,str1)<<endl; //if str1<str2-> -ve || if str1==str2-> 0 || if str1>str2 ->+ve;
  return 0;
}
