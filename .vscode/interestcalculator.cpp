#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cout<<"enter the principle value"<<endl;
  cin>>a;
  cout<<"enter the rate of interest"<<endl;
  cin>>b;
  cout<<"enter the time period"<<endl;
  cin>>c;
  float S_I=(a*b*c)/100;
  cout<<"the simple interest on input value is "<<S_I<<endl;
  return 0;
}