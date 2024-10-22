#include <iostream>
using namespace std ;
int main()
{ int income;
long long int tax=0;
cout<<"enter your income (in Lakhs) :"<<endl;
cin>>income;
if(income<5){
  cout<<"you are not applicable for paying tax"<<endl;
}
else if(income<=10){
  tax=(0.2*income)*100000;
  cout<<"you are applicable for "<<tax<<" as tax"<<endl;
}
else{
  tax=(0.3*income)*100000;
  cout<<"you are apllicable "<<tax<<" as a tax"<<endl;
}

  return 0;
}