#include <iostream>
using namespace std;
int main(){
  int a,b;
  cout<<"enter the number to calculate"<<endl;
  cin>>a>>b;
  char ch;
  cout<<"enter the character to operate"<<endl;
  cin>>ch;
  switch (ch)
  {
  case '+':
    cout<<"sum is :"<<a+b<<endl;
        break;
  case '-':
    cout<<"difference is :"<<a-b<<endl;
    break;
  case '*':
    cout<<"the product is :"<<a*b<<endl;
    break;
  case '/':
    cout<<"the divison is :"<<a/b<<endl;
    break;
default:
    cout<<"invalid character"<<endl;
    break;
  }
  return 0;
}