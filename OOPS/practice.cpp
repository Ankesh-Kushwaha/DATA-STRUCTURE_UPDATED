#include <iostream>
using namespace std;
class user{
  int id;
  int password;
public:
  string username;
  //constructor;
  user(int id){
    cout<<"constructor called"<<endl;
    this->id=id;
  }
   //setter
  void setpassword(int password){
    this->password=password;
  }
 
 //getter
  int getpassword(){
    return password;
  }

};
int main(){
  user u1(1234);
  u1.setpassword(964838);
  u1.username="Ankesh Kushwaha";
  cout<<u1.username<<endl;
  cout<<u1.getpassword()<<endl;
  return 0;
}