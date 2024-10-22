#include <iostream>
using namespace std;
int main(){
  int year;
  cout<<"enter the year to search"<<endl;
  cin>>year;
  if(year%4==0){
     cout<<"entered year is a leap year"<<endl;
  }
  else{
    cout<<"entered year is not a leap year"<<endl;
  }
  return 0;
}