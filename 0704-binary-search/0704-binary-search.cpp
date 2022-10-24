/*
    Edge Cases to Check for:
    Our input can have 1 value
    Numbers are unique
    There will be no extra values in array, just numbers
    
    General Solution:
    
    By using binary search we can quickly acheive big O (log(n));
    
    
    grab the lowest index, and the highest index and divide that by 2
    
    create a while loop that check to see if number exists, if it does,
    return index, if not, continue checking if higher or lower. 
    
    
    Constraints: 
    
    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.
    
    Input: Array of Numbers and Target
    Output: Array Index
    
    Pseudo code:
    
    low = 0;
    high = nums.size() - 1;
    
    mid = low + high / 2; 
    
    while(low < high) {
        if(nums[mid] == target) {
            return mid; 
        }
        else if(nums[mid] > target) {
            low = mid + 1; 
            mid = low + high / 2;
        } else {
            high = mid - 1; 
            mid = low + high / 2;
        }
    }
    
    return false (-1);
*/


/*

    [-1, 0, 3, 5, 9, 12]
               
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1; // 5
        int mid = (low + high) / 2; // 
                
        if(nums[mid] == target) {
            return mid;
        }
        
        while(low <= high) { // 3 < 6
            if(nums[mid] == target) {
                return mid;
            }  else if (nums[mid] < target) { // 3
                low = mid + 1; // 4 
                mid = ((high + low) / 2); // 4 + 5 = 9  
                cout << mid << endl; 
            }  else if(nums[mid] > target) {
                high = mid - 1;
                mid = ((high + low) / 2);
            }
        }
        return -1;
    }
};