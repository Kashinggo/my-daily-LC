// discussion | T: O(NlogN) | S: O(N)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> meetings; // scan line
        for (vector<int> &interval :intervals) {
            meetings.push_back({interval[0], 1});  // on bus
            meetings.push_back({interval[1], -1}); // off bus
        }

        sort(meetings.begin(), meetings.end()); // sort by `pair.first`

        int maxValue = 0, cnt = 0;
        for (auto &meeting : meetings) {
            cnt += meeting.second;
            maxValue = max(maxValue, cnt);
        }

        return maxValue;
    }
};

// clearer than heap