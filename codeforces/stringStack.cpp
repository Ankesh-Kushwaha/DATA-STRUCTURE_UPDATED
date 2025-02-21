#include<iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  string temp = s;
  s = "";
  for (char &c : temp) {
    c = tolower(c);
  }

  for (int i = 0; i < temp.length();)
  {
    if (temp[i] == 'a' || temp[i] == 'o' || temp[i] == 'y' || temp[i] == 'e' || temp[i] == 'u' || temp[i] == 'i')
    {
      temp.erase(i, 1);
    }
    else
    {
      i++;
    }
  }


  for (int i = 0; i < temp.length();i++){
    s.insert(i * 2, ".");
    s.insert(i * 2 + 1, 1, temp[i]);
  }

  cout << s;

  return 0;
}