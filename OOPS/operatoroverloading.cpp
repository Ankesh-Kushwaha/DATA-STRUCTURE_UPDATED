#include <iostream>
using namespace std;

class complex{
int real;
int img;

public:
  complex(int r,int i){  
   this->real=r;
   this ->img=i;
  }

  void shownum(){
    cout<<real<<" + "<<img<<"i"<<endl;
  }
  //operator overloading
  complex operator +(complex &c2){  
      int resReal=this->real+c2.real;
      int resImg=this->img +c2.img;
      complex c3(resReal,resImg);
      return c3;
  }
};

int main(){
  complex c1(1,5);
  complex c2(4,5);

  c1.shownum();
  c2.shownum();
  
  complex c3=c1+c2;
  c3.shownum();

  return 0;
}