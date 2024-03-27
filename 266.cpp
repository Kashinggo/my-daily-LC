// my submission | T: O(N) | S: O(1)

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<bool> mark(26, 0);
        for (auto c : s) {
            mark[c - 'a'] = !mark[c - 'a'];
        }
        bool single = 0;
        for (auto x : mark) {
            if (!single && x) single = 1;
            else if (x) return false;
        }
        return true;
    }
};

// discussion | same