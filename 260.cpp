// discussion | T: O(N) | S: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0,
                             [](int x, int y) { return x ^ y; });

        int k = -1;
        for (int i = 31; i >= 0 && k == -1; --i) {
            if (((sum >> i) & 1) == 1) k = i; // key: which to move
        }

        // `(x - 1) & x ^ x` may cause overflow

        int teamOne = 0, teamZero = 0;
        for (int x : nums) {
            if (((x >> k) & 1) == 1) teamOne ^= x; // always use a single 1
            else teamZero ^= x;
        }

        return {teamZero, teamOne};
    }
};