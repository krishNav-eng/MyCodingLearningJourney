#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> A, B;
        A = nums1, B = nums2;
        if(A.size() > B.size()) {
            A = nums2;
            B = nums1;
        }
        int total = A.size()+B.size();
        int half = total/2;
        int l = 0;
        int r = A.size()-1;
        int i, j, Aleft, Aright, Bleft, Bright;
        while (true) {
            i = (l+r)/2;
            j = half-i-2;

            if(i>=0) Aleft = A[i];
            else Aleft = -1e9;
            if(i<A.size()-1) Aright = A[i+1];
            else Aright = 1e9;

            if(j>=0) Bleft = B[j];
            else Bleft = -1e9;
            if(j<B.size()-1) Bright = B[j+1];
            else Bright = 1e9;

            if(Aleft<=Bright && Bleft<=Aright) {
                // correct partition
                if(total%2 == 0) return (double)(max(Aleft, Bleft)+min(Aright, Bright))/2;
                else return min(Aright, Bright);
            }
            else if (Aleft>Bright) r = i-1;
            else l = i+1;
        }
    }
};
    