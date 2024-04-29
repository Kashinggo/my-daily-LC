// string | both: O(N)
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        int n = currentState.size();
        if (n == 1) return res;

        for (int i = 0; i + 1 < n; ++i) {
            if (currentState.substr(i, 2) == "++") {
                res.push_back(currentState.substr(0, i) + "--" + currentState.substr(i + 2));
            }
        }

        return res;
    }
};
