/*
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    
    General Solution,
        Thankfully, palindromes must be able to "read the same in reverse".
        This is a great attempt at using a two pointer technique;
        
        By using the a pointer on the left side of palindrome,
        Then using a pointer on the right side of palindrome, 
        
        we can iterate through the word and skip spaces.
    
*/

class Solution {
public:
    
    
    string setLowerCase(string s) {
        string lowerString;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                lowerString.push_back(s[i]);
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                lowerString.push_back(tolower(s[i]));
            } else if (s[i] >= '0' && s[i] <= '9') {
                lowerString.push_back(s[i]);
            }
        }   
            return lowerString;
    }
    bool isPalindrome(string s) {
        
        string lowerCase = setLowerCase(s);
        int L = 0; 
        int R = lowerCase.size() - 1;
        
        cout << lowerCase;
        
        while(L < R) {
            if(lowerCase[L] == lowerCase[R]) {
                R--;
                L++;
            } else {
                return false;
            }
        }
        
        return true;
        
    }
};