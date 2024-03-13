// discussion | T: O(n^2 * m) | S: O(n) | m is average length of string
// there's a more consise way using same step hashing, but Union Find is what I need to practise

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // intuition: union find
        unordered_map<string, int> strFreq;
        for (const auto &str : strings) {
            strFreq[str]++;
        }
        UnionFind uf(strings);
        int n = strings.size();
        for (int i = 0; i <n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (strings[i].size() != strings[j].size()) continue;
                if (isShiftedEqual(strings[i], strings[j])) {
                    uf.unite(strings[i], strings[j]);
                }
            }
        }
        map<string, set<string>> mp;
        uf.buildGroupMap(mp);

        vector<vector<string>> res;
        for (const auto &m :mp) {
            vector<string> group;
            for (const auto &str : m.second) {
                if (strFreq[str] > 1) {
                    for (int k = strFreq[str]; k > 0; --k) {
                        group.push_back(str);
                    }
                } else {
                    group.push_back(str);
                }
            }
            res.push_back(group);
        }
        
        return res;
    }


private:
    bool isShiftedEqual(string x, string y) {
        if (x == y) return true;
        auto rightShifted = x;
        for (int i = 0; i < 25; ++i) {
            for (auto &ch :rightShifted) {
                ch = (ch == 'z' ? 'a' : ch + 1);
            }
            if (y == rightShifted) return true;
        }
        return false;
    }

    // pay attention to 'init', 'find', 'merge', the rest is customization
    class UnionFind {
    public:
        UnionFind(vector<string>& strs) { // ensure all have a parent
            for (const auto& str : strs) {
                parent[str] = str;
            }
        }
        string find(string x) {
            if (x == parent[x])
                return x;
            return find(parent[x]);
        }
        void buildGroupMap(map<string, set<string>>& mp) {
            for (const auto& p : parent) {
                auto root = find(p.first);
                mp[root].insert(p.first);
            }
        }
        void unite(string x, string y) {
            auto px = find(x);
            auto py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        }

    private:
        unordered_map<string, string> parent;
    };
};