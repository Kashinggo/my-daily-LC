// my submission | T: O(N^2) | S: O(N)


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
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = INT_MAX;
        inorder(root, target, res);
        return res;
    }

private:
    void inorder(TreeNode* root, double target, int& res) {
        if (!root) return;
        if (abs(target - res) > abs(target - root->val)) {
            res = root->val;
        } else if (abs(target - res) == abs(target - root->val)) {
            res = min(root->val, res);
        }

        if (root->val > target) {
            inorder(root->left, target, res);
        } else if (root->val < target) {
            inorder(root->right, target, res);
        } else {
            res = target;
            return;
        }
    }
};