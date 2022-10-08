/*

    
    Brute force solution: 
    
    Triple For Loop: 
    
    Screw that, we can do better.
    
    1.) Sort Array
    2.) Increment a pointer for "starting letter", then use two pointer to find other two.
    3.) Check to see if i is != one befroe then i++;
    
    
    THINGS TO NOTE:
    1.) Array Unsorted
    2.) Solution set must not contain duplicate triples. 
    


*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> arrOutput;
        sort(nums.begin(), nums.end());
        int s = 0; 
        int L;
        int R;
        set<vector<int>> uniqueValues;
        
        while(s < nums.size()) {
                        
            if(s != 0) {
                if(nums[s] == nums[s - 1]) {
                    s++;
                }
            }
            
            L = s + 1;
            R = nums.size() - 1;
            
            while(L < R) {
                if(nums[s] + nums[L] + nums[R] < 0) {
                    L++;
                } else if(nums[s] + nums[L] + nums[R] > 0) {
                    R--;
                } else if(nums[s] + nums[L] + nums[R] == 0) {
                    uniqueValues.insert({nums[s], nums[L], nums[R]});
                    L++;
                    R--;
                }
            }
            s++;
        }
        
        for(auto vec : uniqueValues) {
            arrOutput.push_back(vec);
        }
        
        return arrOutput;
    }
};