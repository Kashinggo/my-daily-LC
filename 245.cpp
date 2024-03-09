// my submission | T: O(n) | S: O(1)

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int idx1 = -1, idx2 = -1, min_d = INT_MAX;
        // idx1, ..., idx2 ...
        for (int i = 0; i < wordsDict.size(); ++i) {
            string &w = wordsDict[i];
            if (w == word1 && w == word2) {
                if (idx1 == -1 && idx2 == -1) {
                    idx2 = i; continue;
                }
                min_d = min(min_d, min(abs(i - idx1), abs(i - idx2)));
                idx1 = idx2; idx2 = i;   // like dp(climbing stair)
            } else if (w == word1) {
                idx1 = i;
                if (idx2 != -1) min_d = min(min_d, abs(i - idx2));
            } else if (w == word2) {
                idx2 = i;
                if (idx1 != -1) min_d = min(min_d, abs(i - idx1));
            } 
        }
        return min_d;
    }
};

// discussion | same
// `!strcmp(w1, w2)` for c language