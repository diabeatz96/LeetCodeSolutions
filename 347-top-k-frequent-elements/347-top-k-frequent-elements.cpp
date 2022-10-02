/*
    General solution:
    We can create a hash map that counts the amount of elements in the array and adds them to an element, we can then loop through the map
    and find the values with highest values, and continously push them to an array.
    
    Our Constraints:
    
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

    My solution will be O(n) time and O(n) space complexity, because I will be creating a hashmap that stores all elements 
    of the array and looping through that array.
    
    map<int, int> countNumbers;
    int vector<int> topNums(k); 
    
    for(int i = 0; i < nums.size(); i++) {
        countNumbers[nums[i]] += 1;
    }
    
    for(int i = 0; i < k; i++) {
       topNums.push(map[map.size() - i - 1]);
    }
    
    return topNums;
}
    
*/

class Solution {
    

    
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> countNumbers;
        vector<int> topNums;
        
        for(int i = 0; i < nums.size(); i++) {
            countNumbers[nums[i]] += 1;
        }
        
        map<int, int>::iterator it;
        
        
        for(int i = 0; i < k; i++) {
            it = max_element(countNumbers.begin(), countNumbers.end(), [](const auto &x, const auto &y) {return x.second < y.second;});
            topNums.push_back(it->first);
            countNumbers.erase(it);
        }
        
        return topNums;
        
    }
};