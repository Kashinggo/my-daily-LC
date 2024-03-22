// my submission | T: O(N) | S: O(N)

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int i = 1; i <= n; ++i) {

            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];

            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];

            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }

        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};

// discussion | T: O(N) | S: O(1)

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int red = costs[0][0], blue = costs[0][1], green = costs[0][2];

        for (int i = 1; i < costs.size(); ++i) {
            int newRed = min(blue, green) + costs[i][0];
            int newBlue = min(red, green) + costs[i][1];
            int newGreen = min(red, blue) + costs[i][2];
            red = newRed;
            blue = newBlue;
            green = newGreen;
        }

        return min(red, min(blue, green));
    }
};