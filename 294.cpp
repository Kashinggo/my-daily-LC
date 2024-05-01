// backtrace | O(N!) | O(2^N)
class Solution {
public:
    bool canWin(string currentState) {
        if (mp.find(currentState) != mp.end()) return mp[currentState];
        for (int i = 0; i < currentState.size() - 1; ++i) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                currentState[i] = currentState[i + 1] = '-';
                if (!canWin(currentState)) {
                    mp[currentState] = false;
                    return true;
                }
                currentState[i] = currentState[i + 1] = '+';
            }
        }
        mp[currentState] = false;
        return false;
    }
private:
    unordered_map<string, bool> mp;
};
