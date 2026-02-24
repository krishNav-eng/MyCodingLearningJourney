#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<long> st;

        for (const std::string& s : tokens) {
            // Check if the token is an operator
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long val2 = st.top(); st.pop(); // Second operand
                long val1 = st.top(); st.pop(); // First operand
                
                if (s == "+") st.push(val1 + val2);
                else if (s == "-") st.push(val1 - val2);
                else if (s == "*") st.push(val1 * val2);
                else if (s == "/") st.push(val1 / val2);
            } 
            else {
                // It's a number; convert string to long
                st.push(std::stol(s));
            }
        }
        return (int)st.top();
    }
};