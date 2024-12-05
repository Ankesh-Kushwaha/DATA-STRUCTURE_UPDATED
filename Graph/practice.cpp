#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> question;
  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      cin >> question[i][j];
    }
  }

  int ans = 0;
  for(auto q:question){
    for (int i = 0; i < q.size();i++){
      int temp = 0;
      if (q[i] == 1)
      {
        temp++;
        if(temp>=2){
          ans++;
        }
            
        }
    }
  }

  cout<<ans;
  return 0;
}