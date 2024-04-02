// discussion |  T: O(N) | S: O(N)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (auto c : citations) {
            cnt[min(c, n)]++;
        }
        int s = 0;
        for (int i = n;; --i) {
            s += cnt[i];
            if (s >= i) return i;
        }
    }
};