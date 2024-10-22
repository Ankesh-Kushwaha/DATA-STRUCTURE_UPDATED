#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cout<<"enter the cost of pencil:"<<endl;
  cin>>a;
  cout<<"enter the cost of pen"<<endl;
  cin>>b;
  cout<<"enter the cost of eraser:"<<endl;
  cin>>c;
  int total_cost=(a+b+c);
  float total_cost1=total_cost+0.18*(total_cost);
  cout<<"real cost:"<<total_cost<<endl;
  cout<<"cost after GST:"<<total_cost1<<endl;
  return 0;
}