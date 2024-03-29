// my submission | T: O(N) | S: O(N)

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto& str : strs) {
            res += str + "\n\n";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t cur = 0;
        string dmr = "\n\n";
        while (s.find(dmr, cur) != string::npos) {
            auto found = s.find(dmr, cur);
            string str = s.substr(cur, found - cur);

            strs.push_back(str);
            cur = found + dmr.length();
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


// discussion | Carry str length

class Codec {
public:
    // input: {"Hello", "World"}
    // output: "\005\000\000\000Hello\005\000\000\000World"

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;

        for (auto& str : strs) {
            int size = str.size();
            res += string((const char*)&size, sizeof(size));
            res += str;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int index = 0, size = 0;
        while (index != s.size()) {
            memcpy(&size, s.data() + index, sizeof(size));
            index += sizeof(size);
            res.push_back(s.substr(index, size));
            index += size;
        }
        return res;
    }
};
