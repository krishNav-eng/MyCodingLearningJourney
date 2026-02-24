#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        // last occurence of each character
        vector<int> last(26, -1);
        for(int i=0;i<s.size();i++) {
            last[s[i]-'a']=i;
        }
        // stack to store the result
        stack<char> st;

        // visited characters
        vector<bool> visited(26, false);

        for(int i=0;i<s.size();i++) {
            char c=s[i];
            // if character is not visited
            if(!visited[c-'a']) {
                // pop if top is greater than cur char and top is present in future
                while(!st.empty() && st.top()>c && last[st.top()-'a']>i) {
                    visited[st.top()-'a']=false;
                    st.pop();
                }
                st.push(c);
                visited[c-'a']=true;
            }
        }
        string res="";
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};