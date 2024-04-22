// my | T:O(N) | S:O(N)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;
        dfs(v, root, p);
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] == p) return v[i + 1]; 
        }
        return nullptr;
    }
private:
    void dfs(vector<TreeNode*>& v, TreeNode* root, TreeNode* p) {
        if (!root) return;
        dfs(v, root->left, p);
        v.push_back(root);
        dfs(v, root->right, p);
    }
};

// disc | T:O(N) | S:O(1)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        while (root) {
            if (p->val < root->val) {
                res = root; // store in advance
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    return res;
};
// actually don't need to keep track of `prev` all the time
