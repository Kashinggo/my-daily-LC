// discussion | T: O(kN) | S: O(kN)

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));

        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            int tmp1 = INT_MAX, tmp2 = INT_MAX;
            for (int j = 0; j < k; ++j) {
                int& d = dp[i + 1][j];

                if (dp[i][j] != c1) d = costs[i][j] + c1;
                else d = costs[i][j] + c2;

                if (d < tmp1) {
                    tmp2 = tmp1;
                    tmp1 = d;
                } else if (d < tmp2) {
                    tmp2 = d;
                }
            }
            c1 = tmp1;
            c2 = tmp2;
        }

        return *min_element(dp[n].begin(), dp[n].end());
    }
};

// maintain the lowest & 2nd lowest `cost sum`