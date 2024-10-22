#include <iostream>
using namespace std;
void format(int n,char src,char helper,char dest){
  
  if(n==1){
    cout<<"transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    return ;
  }

  //transfer top n-1 disk from src to helper using dest as "helper";
  format(n-1,src,dest,helper);
   cout<<"transfer disk "<<n<<" from "<<src<<" to "<<dest<<endl;
  //transfer top n-1 disk from helper to destination using src as "helper";
  format(n-1,helper,src,dest);
  

}
int main(){
  int n=3;

  format(n,'A','B','C');
  return 0;
}