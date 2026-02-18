#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

/*
LOGIC:
    Using monotonic stacks
    -> instead of looking forward and waiting, we keep a track of elements that are looking for their next greater element.
    Create a STACK for tracking those mentioned elements...
    Create a Map for storing the next greater elements for elements in nums2.
    "Waiting Room" Analogy:
        Think of that stack as the waiting room. 
        Elements enter the waiting room because they haven't find their next greater elements.
    1. Iterate through the list left to right.
    2. Compare: Before an element an element is added to the stack, it looks at the person at the top of the stack "waiting room"
    3. Resolve: If the current element is bigger than the top of the stack, the person on the stack has found its next greater element. 
                Pop them of
    4. Repeat: keep poping until the stack is empty or the current element is smaller than the top.
    5. Push: Finally push the current element to the waiting room i.e stack.

    After all this make a list to storing result.
    1. Iterate: For elements in the num1
    2. Check if it is present in map.
    3. If found push the value of the key from the map to the result (and key is the element of the element in nums1).
    4. If not found push -1 to the result.
*/

class Solution {
public: 
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> waiting_room;
        unordered_map<int, int> ngeMap;

        for(int num:num2) {
            while(!waiting.room.empty() && waiting_room.top() < num) {
                ngeMap[waiting_room.top()] = num;
                waiting_room.pop();
            }
            waiting_room.push(num);
        }

        vector<int> result(nums1.size());
        for(int n:nums1) {
            if(ngeMap.count(n)) {
                result.push_back(ngeMap[n]);
            } else result.push_back(-1);
        }

        return result;
    }
};