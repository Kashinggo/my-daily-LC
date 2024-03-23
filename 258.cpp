// my submission | T: O(1) | S: O(1)

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int remainder = num % 9;
        return (remainder != 0) ? remainder : 9;
    }
};

// discussion | same | (n-1) mod 9 + 1