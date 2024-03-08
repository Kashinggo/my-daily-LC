// my submission | T: O(2*n) | S: O(n)

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            mp[wordsDict[i]].push_back(i); // better use `emplace_back()`
        }
    }
    
    int shortest(string a, string b) {
        int ia = 0, ib = 0, min_d = INT_MAX;
        vector<int> &va = mp[a], &vb = mp[b];
        while (ia < va.size() && ib < vb.size()) {
            min_d = min(min_d, abs(va[ia] - vb[ib]));
            if (min_d == 1) return 1; // really speed up
            if (va[ia] > vb[ib]) {
                ++ib;
            } else {
                ++ia;
            }
        }
        return min_d;
    }
private:
    unordered_map<string, vector<int>> mp;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */


// discussion | same