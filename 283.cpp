// my | T:O(N) | S:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] != 0) {
                nums[l++] = nums[r];
            }
            ++r;
        }
        std::fill(nums.begin() + l, nums.end(), 0); // diff: `v.assign`
    }
};
