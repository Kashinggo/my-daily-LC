# 49

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) {
            vector<int> cnt(26, 0);
            for (char c : s) {
                cnt[c - 'a']++;
            }
            string pat = "";
            for (int i = 0; i < cnt.size(); ++i) {
                pat += to_string('a' + i) + to_string(cnt[i]);
            }
            mp[pat].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
```
