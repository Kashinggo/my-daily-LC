// BFS | both: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string res = "[";
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                res += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "null,";
            }
        }
        res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        string strs = data.substr(1, data.size() - 2);
        stringstream ss(strs);
        string item;
        vector<string> vals;
        while (getline(ss, item, ',')) vals.push_back(item);

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (vals[i] != "null") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            ++i;
            if (vals[i] != "null") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            ++i;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
