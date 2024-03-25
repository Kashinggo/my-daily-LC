// my submission | T: O(logN) | S: O(1)

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
};

// discussion | same