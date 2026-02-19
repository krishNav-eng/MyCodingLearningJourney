#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
LOGIC: Using two Stack
    1. multiplier : stores repeat count
    2. stringStack : stores the previous string
    
    Iterate through string: -> c
        A) If c is a digit : build the entire number (which will be stored in multiplier stack)
        B) If c is '[' : Signals to "save". We push the current string and the current multiplier onto their respective stack.
        C) If c is a character : append it to the current string.
        D) If c is ']' : Signals to expand. Pop the multiplier, repeat the current string that many times and append it 
                         to the previous string popped from the stack. 
*/


class Solution {
    string decodeString(string s) {
        stack<int> multiplier;
        stack<string> stringStack;
        int number=0;
        string current_string="";


        for(char c:s) {
            if(isdigit(c)) number=number*10+(c-'0');
            else if(c=='[') {
                multiplier.push(number);
                stringStack.push(current_string);
                //reset
                current_string="";
                number=0;
            } else if(c==']') {
                int repeatTimes = multiplier.top();
                multiplier.pop();

                string prev_string = stringStack.top();
                stringStack.pop();

                string temp = "";
                for(int i=0;i<repeatTimes;i++) {
                    temp+=current_string;
                }
                current_string=prev_string+temp;
            } else {
                current_string+=c;
            }

            return current_string;
        }
    }
}