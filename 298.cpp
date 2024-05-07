// brute DFS | both: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 1;
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int maxLen = 1;   // attention!

        if (root->left && root->left->val - 1 == root->val) {
            maxLen = left + 1;
        }
        if (root->right && root->right->val - 1 == root->val) {
            maxLen = max(maxLen, right + 1);
        }

        res = max(res, maxLen);
        return maxLen;
    }
};
