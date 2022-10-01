/*
    General Solution:
    
    We can utilize a hash table and generate a "key for each word" using the alpahbet. 
    By maniuplating ascii values, we can develop a "count" for each letter in the alphabet, and push that to a vector. 
    
    After we push all those values to a count, we can then recconver that loop through the current string input and return a string.
    
    Edge Case: if our string has nothing, return an empty array
    Edge Case: Only one value.
    
    since our problem only cosists of lower case english letters, we can use ASCII to manipulate.
               
    steps:
    
    1.) create unordered map
    2.) loop through string values and have each string return a "key"
    3.) Key algorithim with count spaces for each letter position, then push back a string with those letter positions.
    3.) pushback those strings based on the key that exists.
    4.) Iterate through map and pushback into values.
*/

    

class Solution {
public:
    
    string convertKey(string str) {
        vector<int> letterPos(26);
        for(char letter : str) {
            letterPos[letter - 'a']++;
        }
        
        string key = "";
        
        for(int i = 0; i < 26; i++) {
            key += letterPos[i] + 'a';
        }
        
        return key;
        
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringHash;
        vector<vector<string>> stringList;
        
        for(string word: strs) {
            string key = convertKey(word);
            stringHash[key].push_back(word);
        }
        
        
        unordered_map<string, vector<string>>::iterator it;
        for(it = stringHash.begin(); it != stringHash.end(); it++) {
            stringList.push_back(it->second);
        }
        
        return stringList;
    }
};