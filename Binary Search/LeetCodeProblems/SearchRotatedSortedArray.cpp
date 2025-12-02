#include <iostream>
#include <vector>
using namespace std;


// SEARCH IN ROTATED SORTED ARRAY


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m]==target) return m;
            if(nums[m]>=nums[l]){
                // left half of the mid point is sorted correctly!
                // check does the target value lies inside this correctly sorted half
                // otherwise binary search in the other half.
                if(nums[m]>target && nums[l]<=target) r=m-1;
                else l=m+1;
            } else {
                if(nums[m]<target && nums[r]>=target) l=m+1;
                else r=m-1;
            }
        }
        return -1
    }
};