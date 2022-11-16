/*

Array is in ascending order and distinct
Distinct...? 

Array is seperated into two seperate sorted portions, we must check 
to see if each portion on each side is correctly sorted. 


check 7

L = 0;
R = 0;


while (L <= R) {
    if(mi)
}
if ( mid == target) {
    return mid;
}
if (arr[L] > arr[R] && target > arr[L]) {
    
} else if (arr[R] < arr[L] && target < arr[R])


return -1;
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        
        while(L <= R)  {
            int mid = (L + R) / 2;
            
            if(nums[mid] == target) {
                return mid;
            }
            
            if(nums[L] <= nums[mid]) {
              if(target > nums[mid] || target < nums[L]) {
                L = mid + 1; 
              } else {
                R = mid - 1;
              }
            } else {
              if(target < nums[mid] || target > nums[R]) {
                  R = mid - 1;
              } else {
                  L = mid + 1;     
              } 
            }
        }
    return -1;
    }
};