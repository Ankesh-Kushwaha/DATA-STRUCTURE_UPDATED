#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string compressedString(string word)
{
  unordered_map<char, int> mp;
  string comp = "";
  for (int i = 0; i < word.length(); i++)
  {
    if (mp.count(word[i]))
    {
      mp[word[i]]++;
    }
    else
    {
      mp[word[i]] = 1;
    }
  }

  int idx = 0;
  while (idx <= word.length())
  {
    if (mp.count(word[idx]))
    {
      if (mp[word[idx]] >= 9)
      {
        comp.push_back('9');
        comp.push_back(word[idx]);
        mp[word[idx]] = -9;
      }

      else
      {
        comp.push_back(char(mp[word[idx]]));
        comp.push_back(word[idx]);
      }
    }

    idx += mp[word[idx]];
  }

  return comp;
}

int main(){
  string str = "aaaaaaaaaaaaaabb";
  cout << compressedString(str) << endl;

  return 0;
}