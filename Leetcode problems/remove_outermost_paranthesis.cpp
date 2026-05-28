#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // without stacks
    string removeOuterParentheses(string s) {
        vector<string> res;
        int opened = 0;
        for (char c : s) {
            if(c=='(') {
                if(opened>0) res.push_back(c);
                opened+=1;
            } else {
                opened-=1;
                if(opened>0) res.push_back(c);
            }
        }
        string result = "";
        for (const string& str : res) {
            result += str;
        }
        return result;
    }

    // using stacks
    string removeOuterParentheses(string s) {
        vector<char> res;
        stack<char> st;

        for(char c : s){
            if(c=='('){
                if(!st.empty()) res.push_back(c);
                st.push(c);
            } else {
                st.pop();
                if(!st.empty()) res.push_back(c);
            }
        }
        return string(res.begin(), res.end());  
    }

};