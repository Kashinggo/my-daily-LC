// discussion | T: O(5^(n/2)) | S: O(n + 5^(n/2))

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        // 1..1 8..8 6..9 9..6
        return recur(n, n);
    }
    vector<string> recur(int m , int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};

        vector<string> v = recur(m - 2, n);
        vector<string> ans;
        for (auto &x : v) {
            if (n != m) ans.emplace_back("0" + x + "0");
            ans.emplace_back("1" + x + "1");
            ans.emplace_back("8" + x + "8");
            ans.emplace_back("6" + x + "9");
            ans.emplace_back("9" + x + "6");
        }

        return ans;
    }
};

// dry run, 大事だよ