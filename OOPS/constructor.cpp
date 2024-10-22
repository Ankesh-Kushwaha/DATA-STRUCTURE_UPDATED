#include <iostream>
using namespace std;
class car{
  string name;
  string color;

 public:
 car(){
  cout<<"constructor without parameter"<<endl;
 }

 //constructor; called automaticcaly during creation of object;
 car(string name,string color){
  cout<<"constructor with parameter"<<endl;
  this->name=name;
  this->color=color;
 }

  void start(){
    cout<<"car has started:"<<endl;
  }
  
  void stop(){
    cout<<"car has started:"<<endl;
  }

  string getname(){
    return name;
  }
  string getcolor(){
    return color;
  }
};

int main(){
  car c0; //non-parameterised constructor called;
  car c1("maruti 800","white");//paramaterised constructor called;
  car c2("Fortuner","white");
  cout<<c1.getname()<<endl;
  cout<<c1.getcolor()<<endl;

  return 0;
}