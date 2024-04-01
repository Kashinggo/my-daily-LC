// discussion |  T: O(logN) | S: O(logN)

class Solution {
public:
    string numberToWords(int num) {
        if (!num)
            return num2strSmall[0];
        string res = "";
        for (int i = (int)1e9, j = 0; i >= 1; i /= 1000, ++j) {
            if (num < i)
                continue;
            res += (num2Str(num / i) + num2StrLarge[j] + " ");
            num %= i;
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }

private: // similar to Roman digit
    vector<string> num2strSmall{"Zero",    "One",       "Two",      "Three",
                                "Four",    "Five",      "Six",      "Seven",
                                "Eight",   "Nine",      "Ten",      "Eleven",
                                "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                                "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> num2StrMedium{"",       "",      "Twenty", "Thirty",
                                 "Forty",  "Fifty", "Sixty",  "Seventy",
                                 "Eighty", "Ninety"};
    vector<string> num2StrLarge{"Billion", "Million", "Thousand", ""};

    string num2Str(int x) {
        string ans = "";
        if (x >= 100) {
            ans += num2strSmall[x / 100] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            ans += num2StrMedium[x / 10] + " ";
            x %= 10;
        }
        if (x != 0)
            ans += num2strSmall[x] + " ";
        return ans;
    }
};