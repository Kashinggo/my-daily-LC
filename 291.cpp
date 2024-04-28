// backtrace, hashmap | T:O(len(s)^len(p)) | S:O(len(s))

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> mp; unordered_set<string> st;
        return dfs(pattern, s, 0, 0, mp, st); 
    }
private:
    bool dfs(const string &p, const string &s, int idx1, int idx2, unordered_map<char, string> & mp, unordered_set<string> &st) {
        if (idx1 == p.size()) return idx2 == s.size(); // ensure `s` also ends
        char c = p[idx1];
        
        // this pair added before
        if (mp.find(c) != mp.end()) {
            string word = mp[c];
            if ((idx2 + word.size() <= s.size()) && (s.substr(idx2, word.size()) == word)) {
                return dfs(p, s, idx1 + 1, idx2 + word.size(), mp, st);
            }
            return false;
        }

        // not added before
        for (int i = idx2 + 1; i <= s.size(); ++i) {
            string word = s.substr(idx2, i - idx2);
            if (!st.count(word)) {
                mp[c] = word;
                st.insert(word);
                if (dfs(p, s, idx1 + 1, i, mp, st)) return true; // backtrace
                // recover
                mp.erase(c);
                st.erase(word);
            }
        }

        return false;
    }
};
