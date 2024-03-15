// my submission | T: O(N) | S: O(H)

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
    int countUnivalSubtrees(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
private:
    bool dfs(TreeNode *root, int &cnt) {
        if (!root) return true;
        // if (dfs(root->left, cnt) && dfs(root->right, cnt)) // `&&` causes short circuit
        bool c1 = dfs(root->left, cnt);
        bool c2 = dfs(root->right, cnt);
        if (c1 && c2) {
            if (root->left && root->left->val != root->val) return false;
            if (root->right && root->right->val != root->val) return false;
            ++cnt; return true;
        }
        return false;
    }
};