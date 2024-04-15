// discussion | T: O(N) | S: O(N)

class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (i > 2) {
                dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
                // cur = prev1 * (k - 1) + prev2 * (k - 1); prev2 = prev1; prev1 = cur; 
            } else if (i == 2) {
                dp[i] = k * k;
            } else {
                dp[i] = k;
            }
        }
        return dp[n];
    }
};
