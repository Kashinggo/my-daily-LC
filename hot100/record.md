# medium & hard

## 34. Find First and Last Position of Element in Sorted Array

acwing 模版:

- 注意 m = l + r + 1 >> 1 配合 l = m，不会 inf loop
- m = l + r >> 1 配合 l = m + 1

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (!nums.size()) return res;
        int a = firstIdx(nums, target), b = lastIdx(nums, target);
        if (a == -1) return res;
        res[0] = a; res[1] = b;
        return res;
    }
private:
    int firstIdx(vector<int> &nums, int t) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + r >> 1;
            if (nums[m] < t) {
                l = m + 1;
            } else if (nums[m] > t) {
                r = m;
            } else {
                r = m;
            }
        }
        if (nums[l] != t) return -1;
        return l;
    }

    int lastIdx(vector<int> &nums, int t) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (nums[m] > t) {
                r = m - 1;
            } else if (nums[m] < t) {
                l = m;
            } else {
                l = m;
            }
        }
        if (nums[l] != t) return -1;
        return l;
    }
};
```

## 128. Longest Consecutive Sequence

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (st.count(num)) {
                st.erase(num);
                int sum = 1 + left_cnt(num, st) + right_cnt(num, st);
                res = max(sum, res);
            }
        }
        return res;
    }
private:
    int left_cnt(int center, unordered_set<int> &st) {
        int cnt = 0;
        for (int i = center - 1; ; --i) {
            if (st.count(i)) {
                ++cnt;
                st.erase(i);
            } else {
                break;
            }
        }
        return cnt;
    }
    int right_cnt(int center, unordered_set<int> &st) {
        int cnt = 0;
        for (int i = center + 1; ; ++i) {
             if (st.count(i)) {
                 ++cnt;
                 st.erase(i);
             } else {
                 break;
             }
        }
        return cnt;
    }
};
```

参考：只挑选无相邻更小的元素，向上查找，则无需 erase 操作

## 49. Group Anagrams

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

参考其他解法：

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
