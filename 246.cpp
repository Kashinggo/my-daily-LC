// my submission | T: O(n) | S: O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
        // 1 2 3 4 5 6 7 8 9 0
        // 1         9   8 6 0
        vector<int> mp(10, -1);
        mp[0] = 0; mp[1] = 1; mp[6] = 9; mp[8] = 8; mp[9] = 6;
        int n = num.size(), i = 0, j = n - 1;
        while (i <= j) {
            if ((num[i] - '0') != (mp[num[j] - '0'])) return false;
            ++i; --j;
        }
        return true;
    }
};

// discussion | same
unordered_map<char, char> mp{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
vector<int> v{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};