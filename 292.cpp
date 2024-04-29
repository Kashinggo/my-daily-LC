// game theory | both: O(1)
class Solution {
public:
    bool canWinNim(int n) {
        // 1 -> w
        // 2 -> w
        // 3 -> w
        // 4 -> l
        // 8 -> l
        // 12 -> w
        return n % 4 != 0;
    }
};
