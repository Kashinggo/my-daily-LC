// discussion | T: O(log(N) * sqrt(N)) | S: O(N)

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        return recur(n, 2);
    }
private:
    vector<vector<int>> recur(int n, int start) {
        vector<vector<int>> res;

        for (int i = start; i <= n / i; ++i) {
            if (n % i == 0) {
                res.push_back({n / i, i}); // when len = 2
                for (vector<int> v : recur(n / i, i)) {
                    v.push_back(i); // smallest at last
                    res.push_back(v); // overall res
                }
            }
        }
        return res;
    }
};

// backtracing