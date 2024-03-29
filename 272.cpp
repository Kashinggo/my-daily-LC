// discussion | T: O(NlogN) | S: O(N)

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        dfs(root, target);
        int i = 0;
        while (i < k) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
            ++i;
        }
        return res;
    }

private:
    void dfs(TreeNode* node, double target) {
        if (!node)
            return;

        int second = node->val;
        double first = abs((double)node->val - target);

        minHeap.push(pair<double, int>(first, second));
        dfs(node->left, target);
        dfs(node->right, target);
    }

    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>> minHeap;
};

// easy to implement, for better performance, try `sliding window`
// which is O(N), O(logN))