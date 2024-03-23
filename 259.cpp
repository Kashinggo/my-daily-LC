// discussion | T: O(N^2) | S: O(1)

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            res += twoSumSmaller(nums, i + 1, target - nums[i]);
        }

        return res;
    }

private:
    int twoSumSmaller(vector<int>& nums, int startIdx, int target) {
        int sum = 0, l = startIdx, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                sum += r - l;
                ++l; // key, not over yet
            } else {
                --r;
            }
        }
        return sum;
    }
};