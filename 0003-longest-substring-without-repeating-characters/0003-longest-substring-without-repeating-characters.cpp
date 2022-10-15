/*

    Edge cases:
    
    Always a string, but can have special character (NO ASCII Shenanigans)
    String can be empty, utilize an edge case for this
    
    Key Concepts:
    
    Without repeating characters - AKA no duplicates, perfect for a set. 
    Add to an empty set. 
--------------------------------------------------------------------------------


    [abcabcbb]
    

    
    Algorithim Steps (General) :
    
    
    Input/Output:
    
    String
    Integer of longest sub length;
    
    Variables/Data Structers:
    1.) maxLength;
    2.) currLength;
    3.) set for storing values;

    1.) Create a set to hold values from string. 
    2.) Create max length variable
    3.) Loop through characters, if character is not in the set, add it,
    4.) if character is in set, subtract currlength of best substring. --; 
    5.) return length variable at end
    
    
    
    
    lengthofSubstring (string s) {
        
    }
    
    


*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> characters;
        int maxLength = 0; 
        int currLength = 0;
        int R = 0, L = 0;
        
        
        while(R < s.size()) {
            if(!characters.count(s[R])) {
                characters.insert(s[R]);
                currLength = R - L + 1;
                maxLength = max(currLength, maxLength);
                R++;    
            } else {
                characters.erase(s[L]);
                L++;
            }        
    }
        return maxLength; 
}
};