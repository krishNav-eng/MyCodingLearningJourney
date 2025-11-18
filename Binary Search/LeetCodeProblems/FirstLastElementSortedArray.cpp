#include <iostream>
#include <vector>
using namespace std;

// FIND FIRST AND LAST POSITION OF ELEMENT IN SORTED ARRAY

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l, r, mid;
        vector<int> result(2, -1);
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            mid = (l+r)/2;
            if (nums[mid] == target) {
                int k = mid;
                while (k-1 >= 0 && nums[k-1] == target) {
                    k--;
                }
                result[0] = k;
                k = mid;
                while (k+1 < nums.size() && nums[k+1] == target) {
                    k++;
                }
                result[1] = k;
                return result;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};