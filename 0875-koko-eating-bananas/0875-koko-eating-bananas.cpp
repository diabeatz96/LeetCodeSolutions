/*

We know the maximum value
and then use binary search,

O(n);

O(log(Max(pSize)) * 2n)


Min of the output
output = min[k];

Binary Search

if for 
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int L = 1, R = 0;
        long int mid;
        long int res = 0;
        
        
        /* find max value in array of eating speed */
        
        for(int i = 0; i < piles.size(); i++) {
            R = max((int)R, (int)piles[i]);
        }
        
        res = R; 
        
        
        while(L <= R) {
            long int hours = 0;
            mid = (L + R) / 2;
            for(int i = 0; i < piles.size(); i++) {
                hours += ceil((double) piles[i] / mid);
            }            
            
            if(hours <= h) {
                res = min((int)res, (int)mid);
                R = mid - 1;
            } else {
                L = mid + 1;
            }
            

        } 
        return res;    
    }
};