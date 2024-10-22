#include <iostream>
//symbolic constants
#define X 4; //macros does not take any extra space in our memory they where instantly replace by the variable defined at that place
using namespace std;
int main (){
  const float PI=3.1473; //where as const take space in the memory 
  cout<<PI<<endl;
  return 0;
}