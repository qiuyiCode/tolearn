#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeElement(vector<int> &nums, int val){
    int j = nums.size()-1; // 第二个指针从最后开始
    for(int i = 0;i <= j;i++){
      while(j >= i && nums[j] == val) j--; // 为什么要取j >= i,可能存在nums = [1],val = 1的情况

      if(j >= i && nums[i] == val){
        swap(nums[i],nums[j]);
      }

    }
    return j+1;
  }
};

