/*

    Two Sum ||. Input Array Sorted.
    
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;
        int currSum;
        vector<int> result;
        
        
        while(L < R) {
            currSum = numbers[L] + numbers[R];
            cout << currSum << endl;
            if(currSum == target) {
                result.push_back(L + 1);
                result.push_back(R + 1);
                return result;
            }
            
            if(currSum < target) {
                L++;
            } else {
                R--;
            }
        }
        return result;
    }
};