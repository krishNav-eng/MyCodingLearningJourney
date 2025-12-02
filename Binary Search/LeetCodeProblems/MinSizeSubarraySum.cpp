#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sums += nums[right];

            
        }
        
    }
private:
    int intuitiveApproach(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;

        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum += nums[end];
                if (sum >= target) {
                    minLength = min(minLength, end - start + 1);
                    break; // No need to check further for this start
                }
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }

    int slidingWindowApproach(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};