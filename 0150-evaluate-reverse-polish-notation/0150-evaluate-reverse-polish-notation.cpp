/*


    1.) Our constraints allow us to make it so that there is only an operator and number value associated with it. 
    2.) Addition, Subtraction, Multiplication. 
    Utilizing a stack, we solve "polish" notation
    
    
    for our stack, we can survery through each input and check to see whether
    it is an operation or a number. 
    
    GENERAL ALGORITHIM:
    
    1.) create a stack to hold all values.
    2.) inside of a stack you "push" value onto it, if stack == # move on with push operation:
    3.) If the stack push is a + or *, you pop last two values from the stack, then pop last twp values, and then re-push that value back onto the stack after operation is finished. 
    4.) return the top of stack after results are finished.
    




*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> postFix; 
        
        for (string val: tokens) {
            long op2;
            long op1;
            long value;
            if(val == "+") {  
              op2 = postFix.top();
              postFix.pop();
              op1 = postFix.top();
              postFix.pop();
              long value = op1 + op2; 
              postFix.push(value);
            } else if(val == "-") {
              op2 = postFix.top();
              postFix.pop();
              op1 = postFix.top();
              postFix.pop();
              long value = op1 - op2; 
              postFix.push(value); 
            } else if (val == "/") {
              op2 = postFix.top();
              postFix.pop();
              op1 = postFix.top();
              postFix.pop();
              long value = op1 / op2; 
              postFix.push(value);
            } else if (val == "*") {
              op2 = postFix.top();
              postFix.pop();
              op1 = postFix.top();
              postFix.pop();
              long value = op1 * op2; 
              postFix.push(value);
            } else {
                postFix.push(stoi(val));
            }
        }
        return  postFix.top();
    }
};