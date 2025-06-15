// Binary Tree Right Side View (#199)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (root == nullptr) return rightView;

        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                // If it's the last node of the level, add to result
                if (i == levelSize - 1) {
                    rightView.push_back(current->val);
                }

                // Add left and right children to the queue
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }

        return rightView;
    }
};