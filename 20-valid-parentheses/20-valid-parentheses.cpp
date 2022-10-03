/*
    General Solution:
    
    Clearly, we must utilize a stack in our case,
    
    1.) We will create an empty stack that will represent parameters (closing and opening braces)
    2.) When we encounter an opening brace, we push it to the stack. 
    3.) If we encounter a closing brace and stack is empty, we return false;
    
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        
        for(int i = 0; i < s.size(); i++) {
            
            if((s[i] == '}' || s[i] == ')' || s[i] == ']') && pStack.empty()) {
                return false; 
            }
            
            
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                pStack.push(s[i]);
            } else {
                if (s[i] == '}' && pStack.top() != '{') {
                    return false;
                } else if(s[i] == ']' && pStack.top() != '[') {
                    return false;
                } else if (s[i] == ')' && pStack.top() != '(') {
                    return false;
                } else {
                    pStack.pop();
                }
            }
        }
        return pStack.empty(); 
    }
};