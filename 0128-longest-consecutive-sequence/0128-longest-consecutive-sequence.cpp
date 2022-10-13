/*
    - Longest Consecutive Sequence -
       -  -   -   -  -  -
    [100, 4, 200, 1, 3, 2]
        
        
    Input: an array of unsorted numbers; 
    Output: The length of sequence.
    
    1.) loop through our nums array by the size of the array, 
    
        so we will loop O (n); 
        
    
        Our Constraints:
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
        
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        unordered_set<int> numCopy = {nums.begin(), nums.end()};
        int longestSequence = 0; 
        
        for(int i = 0; i < nums.size(); i++) {
            if(!numCopy.count(nums[i] - 1)) {
                int length = 1;
                while(numCopy.count(nums[i] + length)) {
                    length++;
                }
                longestSequence = max(longestSequence, length);
        }
    }
        return longestSequence;
    }
};