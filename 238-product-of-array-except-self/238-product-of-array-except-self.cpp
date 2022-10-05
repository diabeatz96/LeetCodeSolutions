/*
    
    General Solution: We can potentially solve this problem using pre-fix sums.
    We can generate the product of all positions in sub array
     24 12 8 4
     1  2  6  24 
    [1, 2, 3, 4];
    [-1, 1, 0, -3, 3];
    
    
    
    Examples: 
    
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
    
    Two passes, one pass for a pre-fix sum;
    The second pass we can do with a post-fix sum;
    
    twin arrays 
    one to hold prefix, one to hold postfix,

    third array to push answer;
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> preFix;
        vector<int> postFix(nums.size()); 
        vector<int> answer;
        
        int num; 
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                num = nums[i];
                preFix.push_back(num);
            } else {
                num *= nums[i]; 
                preFix.push_back(num);
            }
            
            cout << "Pre Fix" << preFix[i] << endl;
        }
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i == nums.size() - 1) {
                num = nums[i];
                postFix[i] = num;
            } else {
                num *= nums[i]; 
                postFix[i] = num;
            }
            
            cout << "Post Fix" << postFix[i] << endl;
        }
        
        
        int L = 0;
        for(int R = 0; R < nums.size(); R++) {
            if(R == 0) {
                answer.push_back(postFix[R + 1]);
            } else if(R == nums.size() - 1) {
                answer.push_back(preFix[R - 1]);
            } else {
                answer.push_back(preFix[L] * postFix[R + 1]);
                L++;
            }
        }
        
        return answer;
        
    }
};