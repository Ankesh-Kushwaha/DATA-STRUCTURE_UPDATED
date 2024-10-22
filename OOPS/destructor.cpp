#include <iostream>
#include <string>
using namespace std;

class car{
 public:
    string name;
    string color;
    int *mileage;
  
  car(string name,string color){
    cout<<"constructor called"<<endl;
    this ->name=name;
    this ->color=color;
    mileage=new int; //dynamic alloaction;
    *mileage=12;
  }

  //custom copy constructor;
  car(car &original){
    cout<<"copy original to new:"<<endl;
    name=original.name;
    color=original.name;
    mileage=new int; // making of deep copy;
    *mileage=*original.mileage;
  }

  //destructor;
  ~car(){
    cout<<"deleting object"<<endl;
    if(mileage!=NULL){
      delete mileage;
      mileage=NULL;
    }
  }
};

int main(){

car c1("maruti 800","white");
cout<<c1.name<<endl;
cout<<c1.color<<endl;
cout<<*c1.mileage<<endl;










  //  car c1("maruti 800","white");
  //  car c2(c1);

  //  cout<<c2.name<<endl;
  //  cout<<c2.color<<endl;
  //  cout<<*c2.mileage<<endl;
  //  *c2.mileage=10;
  //  cout<<*c2.mileage<<endl;

  //  cout<<*c1.mileage<<endl; //deep copy;
  return 0;
}