#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]==target) return true;
            if(nums[l]==nums[m] && nums[m]==nums[r]){
                // cannot decide which part is sorted, just shrink the search space
                l++; r--;
            } else
            if(nums[m]>=nums[l]){
                if(nums[m]>target && nums[l]<=target) r=m-1;
                else l=m+1;
            } else {
                if(nums[r]>=target && nums[m]<target) l=m+1;
                else r=m-1;
            }
        }
        return false;
    }
};