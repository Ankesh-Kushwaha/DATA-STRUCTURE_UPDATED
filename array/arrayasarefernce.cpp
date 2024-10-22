#include <iostream>
using namespace std;

void func(int arr[]){
  arr[0]=1000;

}
int main(){
  int arr[]={1,2,3,4,5,88,9,10};
  cout<<arr<<endl;
  cout<<*arr<<endl;
  cout<<*arr+1<<endl;
  cout<<*arr+4<<endl;
  func(arr);
  cout<<arr[0]<<endl;
  return 0;
}