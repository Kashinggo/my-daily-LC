// discussion | T: O(logN) | S: O(1)

class Solution {
public:
    int hIndex(vector<int>& cs) {
        int n = cs.size(), l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (cs[mid] >= n - mid) r = mid;
            else l = mid + 1;
        }
        return cs[r] >= n - r ? n - r : 0;
    }
};


// my demo
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // binary search
        int l = 0, n = citations.size(), r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = n - m;
            if (citations[m] > m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};


