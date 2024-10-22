#include <iostream>
using namespace std;

class Parent{
  public:
    void show(){
      cout<<"parent class Show"<<endl;
    }

    virtual void hello(){
       cout<<"parent hello"<<endl;
    }
};

class child:public Parent{
  public:
    void show(){
      cout<<"child class show"<<endl;
    }

    void hello(){ //redefine in child class;
      cout<<"child hello"<<endl;
    }
};

int main(){
  child c1;
  Parent *ptr;
  ptr=&c1;  //run time binding;
  ptr->hello(); //virtual function
  return 0;
}