// discussion | T: O(N ⋅ (N / 2)!) | S: O((N / 2)!)

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int n = s.size();
        for (auto c : s) freqMp[c]++;

        int oddCnt = 0;
        char oddChar;
        for (auto [c, freq] : freqMp) {
            if (freq % 2 == 1) {
                oddCnt++;
                oddChar = c;
                if (oddCnt > 1) return {};
            }
        }

        string mid = "";
        if (oddCnt == 1) {
            mid += oddChar;
            freqMp[oddChar]--;
        }
        dfsBacktrace(mid, n);

        return res;
    }

private:
    void dfsBacktrace(string cur, int n) {
        if (cur.size() == n) res.push_back(cur);
        if (cur.size() >= n) return;

        for (auto [c, freq] : freqMp) {
            if (freq > 0) {
                freqMp[c] -= 2;
                dfsBacktrace(c + cur + c, n);
                freqMp[c] += 2; // recover
            }
        }

        return;
    }

    unordered_map<char, int> freqMp;
    vector<string> res;
};