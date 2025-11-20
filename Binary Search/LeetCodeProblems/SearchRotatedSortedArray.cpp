#include <iostream>
#include <vector>
using namespace std;


// SEARCH IN ROTATED SORTED ARRAY


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while(l<=r) {
            mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
               if (nums[l]<nums[mid]){ //left partition
                    r = mid-1;
                } else if (nums[l]>nums[mid]) { // right partition
                    l = mid+1;
                }
            }
            else {
                if (nums[l]<nums[mid]) { // left partition
                    l = mid+1;
                } else if (nums[l]>nums[mid]) { // right partition
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};