#include <bits/stdc++.h>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }

    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLength = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }

    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        int maxLength = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }


    int without_dp(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }


    int without_binary_search(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp;
        for (int num : nums) {
            bool placed = false;
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i] >= num) {
                    dp[i] = num;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                dp.push_back(num);
            }
        }
        return dp.size();
    }

    int intuitive_approach(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            int length = 1;
            int j = i+1;
            while(nums[j] > nums[i] && j < n) {
                length++;
                j++;
            }
            maxLength = max(maxLength, length);
        }
    }

    int brute_force(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        int maxLength = 1;
        for (int i = n-1; i>=0, i--) {
            for (int j=i+1; j<n; j++) {
                if(nums[j]>nums[i]){
                    maxLength = max(maxLength, LIS[i]);
                }
            }
        }
        return maxLength;
    }

};