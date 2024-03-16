// my submission | T: O(NlogN) | S: O(1)

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};

// discussion | T: O(NlogN) | S: O(N)

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> delta; // sorted by key
        for (auto &interval : intervals) {
            delta[interval[0]]++;
            delta[interval[1]]--;
        }
        int d = 0; // number of meetings now
        for (auto p : delta) {
            d += p.second;
            if (d > 1) return false;
        }
        return true;
    }
};
// discrete