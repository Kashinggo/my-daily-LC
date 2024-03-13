// hard, a bit rush for tonight's EC

// discussion | T: O(n) | S: O(n)
class Solution {
public:
    vector<char> A = {'0', '1', '8'};
    unordered_map<char, char> B = {{'6', '9'}, {'9', '6'}};
    // string cmp
    bool num_less(string n1, string n2) {
        if (n1.size() != n2.size())
            return n1.size() < n2.size();
        return n1 <= n2;
    }
    int strobogrammaticInRange(string low, string high) {
        int len1 = low.size(), len2 = high.size(), res = 0;
        // check first, if base cases satisfy
        vector<string> dp1{""}, dp2{"0", "1", "8"};
        for (auto& s : dp2) res += (num_less(s, high) && num_less(low, s));
        // start building
        for (int i = 2; i <= len2; ++i) {
            vector<string> dp;
            for (auto& s : dp1) {
                for (auto& c : A) dp.push_back(c + s + c); // 018
                for (auto& p : B) dp.push_back(p.first + s + p.second); // 69
            }
            dp1 = dp2;
            dp2 = dp;
            // add valid ones, in the final generate-it-all array
            if (i >= len1) for (auto& s : dp) res += num_less(s, high) && num_less(low, s) && s[0] != '0';
        }
        return res;
    }
};

// DFS or BFS