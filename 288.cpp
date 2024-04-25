// my | T:O(N) | S:O(N)
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dict) {
        for (const auto& w : dict) {
            string ab = abbrify(w);
            if (mp.find(ab) == mp.end()) mp[ab] = w;
            else if (mp[ab] != w) mp[ab] = "-1";
        }
    }

    bool isUnique(string word) {
        string ab = abbrify(word);
        if (mp.find(ab) == mp.end()) return true;
        else return mp[ab] == word;
    }

private:
    string abbrify(const string& s) {
        if (s.size() <= 2) return s;
        return s.front() + to_string(s.size() - 2) + s.back();
    }
    unordered_map<string, string> mp; // abbr -> origin
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
