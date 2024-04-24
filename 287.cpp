// disc | T:O(NlogN) | S:O(1)
class Solution { // no extra space, no modify `nums`
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, n = nums.size(), r = n - 1;
        while (l < r) { // bisec answer range
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= m) ++cnt;
            }
            if (cnt > m) {
                r = m;
            } else { // either equal or less, dup is behind
                l = m + 1;
            }
        }
        return l; 
    }
};

// 2-pointer-find-cycle be trivial for me