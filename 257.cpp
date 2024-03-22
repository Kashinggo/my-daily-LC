/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// my submission | T: O(N^2) | S: O(N^2)

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }

private:
    void dfs(TreeNode* root, string curPath, vector<string>& res) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            curPath += to_string(root->val);
            res.push_back(curPath);
            return;
        }
        curPath += to_string(root->val) + "->";
        dfs(root->left, curPath, res);
        dfs(root->right, curPath, res);
    }
};

// discussion | same, can implement in BFS, too