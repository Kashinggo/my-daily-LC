// my submission | T: O(2*n) | S: O(n)
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> v1, v2;
        for (int i = 0; i <wordsDict.size(); ++i) {
            auto &w = wordsDict[i];
            if (word1 == w) {
                v1.push_back(i);
            } else if (word2 == w) {
                v2.push_back(i);
            }
        }

        int i = 0, j = 0, m = v1.size(), n = v2.size(), min_dis = wordsDict.size();
        while (i < m && j < n) {
            int d = abs(v1[i] - v2[j]);
            min_dis = min(min_dis, d);
            if (v1[i] > v2[j]) {
                ++j;   
            } else if (v1[i] < v2[j]) {
                ++i;
            }
        } 
        return min_dis;
    }
};

// n | 1
// just compare the last seen couterpart, greedy
class Solution {
public:
    int shortestDistance(vector<string>& v, string a, string b) {
        int ia = -1, ib = -1, min_d = INT_MAX;
        for (int i = 0; i < v.size(); ++i) {
            if (a == v[i]) {
                if (ib != -1) min_d = min(min_d, abs(i - ib));
                ia = i;
            } else if (b == v[i]) {
                if (ia != -1) min_d = min(min_d, abs(i - ia));
                ib = i;
            }
        }
        return min_d;
    }
};