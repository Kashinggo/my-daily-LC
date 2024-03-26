// my submission | T: O(N) | S: O(N)

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2) ++p2;
            if (dp[i] == dp[p3] * 3) ++p3;
            if (dp[i] == dp[p5] * 5) ++p5;
        }
        return dp[n];
    }
};

// discussion | same

// try `min heap` for hw | O(NlogN) | O(N)

// priority_queue<long, vector<long>, greater<long>> min_heap;