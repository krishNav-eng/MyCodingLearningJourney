#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int curSum = nums[l]+nums[r];
            if(curSum > target) r--;
            else if(curSum < target) l++;
            else return (vector<int>) {l+1, r+1};
        }
        return (vector<int>) {l+1, r+1};
    }
};