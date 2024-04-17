// my | T: O(logN) | S: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                // can only be earlier
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
