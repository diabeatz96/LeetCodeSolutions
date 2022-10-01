/*

General Solution:

Since we know what the target is, we can go based on the assumption that 

9 - x = y;

We can create a for loop, and loop through an array that checks the values of each number. 

We can potentially even make this not O(n^2) by creating a hash map, and checking in 
that hash map for the value of each number. 

map <int , int> (1st arg number, 2nd arg index position)
(insert all values into a hash map)
for int i; i < arr.length; i++ :
    num = target - arr[i];
    if(map[num]) {
        return int arr[2] = [arr[i], map[num]];
    }

*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arrayIndices; 
        unordered_map<int, int> hashNums;
        
        for(int i = 0; i < nums.size(); i++) {
            hashNums[nums[i]] = i;
        }
        
         for(int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
             if(hashNums[num] && hashNums[num] != i) {
                 arrayIndices.push_back(i);
                 arrayIndices.push_back(hashNums[num]);
                 return arrayIndices; 
             }
        }
    return arrayIndices;
    }
};