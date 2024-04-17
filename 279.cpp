// my | T: O(NsqrtN) | S: O(N)

class Solution {
public:
    int numSquares(int n) {

        int rt = sqrt(n); // pre-check
        if (rt * rt == n) return 1;

        vector<int> sq;
        for (int i = 1; i * i <= n; ++i) {
            sq.push_back(i * i);
        } // sqrtN


        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int x : sq) {
                if (i - x >= 0) {
                    dp[i] = min(dp[i], dp[i - x] + 1);
                } else break;
            }
        } // NsqrtN

        return dp[n];
    }
};
