/* 
    Constraints: 

    1 <= prices.length <= 105
    0 <= prices[i] <= 10

    General Solution: 
    
    We can use a variable fixed sized window to find out which day in the future will be 
    the best.
    
    Variable:
    
     -        -
    ~ [7, 1, 5, 3, 6, 4] ~
    
    
    
    getProfit(arr profit) {
        L, Total  = 0, 0;
        length  = MAX_INT;
        
        for(int R = 0; R < nums.size(); R++)  {
        
        total +=  nums[R];
        
        while total >= target:
        length = min(R - L + 1, length)
        total -= nums[L];
        L+= 1;
        
        }
        
        return length == MAX_INT ? 0 else length;
    }
    
        
    
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum = prices[0];
        int diff = 0;
        int minValue, maxDifference;
        
        for(int i = 1; i < prices.size(); i++) {
            minNum = min(minNum, prices[i]);
            diff = max(diff, prices[i] - minNum);
        }
        return diff;
    }
};