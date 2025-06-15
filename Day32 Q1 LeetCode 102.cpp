// Binary Tree Level Order Traversal (#102)

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        // Use a queue to perform BFS
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at current level
            vector<int> level;

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val); // Add current node's value

                // Enqueue children for next level
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            result.push_back(level); // Add current level to result
        }

        return result;
    }
};