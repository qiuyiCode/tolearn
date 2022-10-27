#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      if(!s.size())
        return true;
      for(int i = 0,j = 0;i < t.size();i++){
        if(s[j] == t[i]){
          j++;
          if(j == s.size())
            return true;
        } 
      }
      return false;
    }

};