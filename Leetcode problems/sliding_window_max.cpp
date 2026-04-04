#include <bits/stdc++.h>
using namespace std;



class SolutionUsingDeque {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // empty deque will store the indices of the elements in the current window
        deque<int> dq;

        // result vector
        vector<int> res;

        for(int i=0;i<nums.size();i++) {
            while(!dq.empty() && nums[i]>nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i-k) dq.pop_front();
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};



class BruteForceSolution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i=0;i<nums.size()-k+1;i++) {
            int m=INT_MIN;
            for(int j=i;j<i+k && j<nums.size(); j++) {
                m=max(m, nums[j]);
            }
            res.push_back(m);
        }
        return res;
    }
};