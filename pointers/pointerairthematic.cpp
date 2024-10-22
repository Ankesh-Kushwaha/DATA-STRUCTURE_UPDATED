#include <iostream>
#include<cmath>
using namespace std;
int main(){
  // int n=10;
  // int *ptr=&n;
  // int **ptr2=&ptr;
  // cout<<ptr<<endl;
  // ptr++;
  // cout<<ptr<<endl;
  // cout<<*ptr2<<endl;
  // ptr--;
  // cout<<ptr<<endl;
  int arr[]={1,2,3,4,5,6};
 int n=sizeof(arr)/sizeof(int);
  cout<<arr<<endl;
  cout<<*arr<<endl;
  for(int i=0;i<n;i++){
    cout<<arr+i<<endl;
  }
  double num=0.25;
  cout<<ceil(num)<<endl;

  return 0;
}