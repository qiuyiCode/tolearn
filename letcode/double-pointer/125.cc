#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int j = s.size()-1;
      for(int i = 0;i <= j;i++){
        if(!isalnum(s[i])){ // isalnum()只包括a-z,A-Z和数字
          continue;
        }

        while(i <= j && !isalnum(s[j])) j--; // 略过空格、标点

        if(tolower(s[i]) != tolower(s[j]))
          return false;
        else{
          j--;
        }
      }
          return true;
    }
};