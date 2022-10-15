/*
    
    Base Case: 
    
    
    
    
    
    General Solution:
    
    
    Area = minHeight * abs(L - R);
    
    
    
    Utilize two pointer technique, develop formula for genera ting max area
    
    While(L != R)
    formula will be min(L, R)  
                    abs(L - R);
    
    if(height[L] < height[R]) {
        L++;
    }
        R--; 
        
    Area = max(currArea, maxArea);
    
    
    Base Case:

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int L = 0, R = height.size() - 1;
        
        while(L != R) {
            int minContainer = min(height[L], height[R]);
            int length = abs(L - R);
            int currArea = minContainer * length;
         
            maxArea = max(currArea, maxArea);
            
            if(height[L] == minContainer) {
                L++;
            } else {
                R--;
            }
            
        }
        return maxArea;
    }
};