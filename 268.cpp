// my submission | T: O(N) | S: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        size_t expectSum = (1 + n) * n / 2;
        size_t sum = accumulate(nums.begin(), nums.end(), 0);
        return static_cast<int>(expectSum - sum);
    }
};

// discussion | T: O(N) | S: O(1) | xor
