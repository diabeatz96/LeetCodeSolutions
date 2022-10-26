class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int R = 0;
    
        for(int i = 0; i < arr.size(); i++) {
            R = i + 1;
            int currMax = INT_MIN;
            while(R < arr.size()) {
                currMax = max(arr[R], currMax);
                R++;
            }
            arr[i] = currMax;
        }
        
        arr[arr.size() - 1] = -1;
        
        return arr;
    }
};