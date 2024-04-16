// discussion |  T: O(N) | S: O(1)

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 1; i < n; ++i) { // max: N calls
            if (knows(res, i)) {
                res = i; // res knows i, res out
            }  // or i out, ++i
        }
        for (int i = 0; i < n; ++i) { // max: 2 * N calls
            if (res == i) continue;
            if (knows(res, i) || !knows(i, res)) return -1;
            //  knows anyone || someone doesn't know you
        }
        return res;
    }
};


// my | T: O(N^2) | S: O(1)
class Solution {
public:
    int findCelebrity(int n) {
        // n * n
        for (int i = 0; i < n; ++i) {
            int j, cnt = 0;
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (knows(i, j)) break; // i know someone, not the res
                if (knows(j, i)) ++cnt;
            }
            if (j == n && cnt == n - 1) return i;
        }
        return -1;
    }
};
