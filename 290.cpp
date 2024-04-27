// hashmap, string oper | T:O(N) | S:O(N)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rmp;
        stringstream ss(s);
        string word;
        
        for (auto c : pattern) {
            if (!(ss >> word) || 
            (mp.find(c) != mp.end() && mp[c] != word) || 
            (rmp.find(word) != rmp.end() && rmp[word] != c)) return false;
            mp[c] = word;
            rmp[word] = c;
        }
        return (ss >> s) ? false : true;
    }
};
