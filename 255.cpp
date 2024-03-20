// my | dfs | T: O(N^2) | S: O(N)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size());
    }
private:
    bool helper(vector<int> &preorder, int start, int end) {
        if (start >= end) return true;
        int rootVal = preorder[start];
        int i = start + 1;
        for (; i < end; ++i) {
            if (preorder[i] > rootVal) break;
        }
        for (int j = i; j < end; ++j) {
            if (preorder[j] < rootVal) return false;
        }
        return helper(preorder, start + 1, i) && helper(preorder, i, end);
    }
};

// discussion | mono stack