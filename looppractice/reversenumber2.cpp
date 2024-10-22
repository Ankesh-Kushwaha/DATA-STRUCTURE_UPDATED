#include <iostream>
#include<math.h>
using namespace std;
int main ()
{int n,new_num=0;
    cout<<"enter the number to reverse:"<<endl;
    cin>>n;
    while(n!=0){
      int r=n%10;
      new_num=new_num*10+r;
      n=n/10;
    }
    cout<<"required new reverse number is :"<<new_num<<endl;
  return 0;
}