/*
    GENERAL SOLUTION:
    
    By utilizing two hash maps, we can compare the amount of characters in each position,
    if both maps are "equal" to each other, then we can return true, else we can return false.
    
    Our solution is O(N), considering we check string length first, and can do one loop through each string to find out if its an anagram or not. 
    
    
    BASE CASES:
    
    We can check to see if each string has the same length, if it dosen't have the same length, we know it can't be the case.
    
    We do not need to check for empty string since our length of string is guarnteed 1 and up.
    
    
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

    
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> stringOne;
        unordered_map<char, int> stringTwo;
        
        if(s.length() != t.length()) {
            return false;
        }
        
        for(int i = 0; i < s.length(); i++) {
            stringOne[s[i]] += 1;
            stringTwo[t[i]] += 1;
        }
        
        return stringOne == stringTwo ? true : false;
    }
};