// math, sort | O(NlogN) | O(MN)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        int size = rows.size(); // number of 1
        sort(cols.begin(), cols.end()); // i already sorted in loop

        int r = rows[size / 2]; // select median, if even, diff'd be same, abs(x1-x2)
        int c = cols[size / 2]; // to ensure distance to two 1 the least, pivot'd be betw them 
        int ans = 0;
        for (int x : rows) ans += abs(x - r);
        for (int y : cols) ans += abs(y - c);

        return ans;
    }
};
