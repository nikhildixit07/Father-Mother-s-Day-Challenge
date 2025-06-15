// Minimum Depth of Binary Tree (#111)

class Solution {
public:
    int minDepth(TreeNode* root) {
        // Edge case: empty tree
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});  // Pair of node and its current depth

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            // If it's a leaf node, return the depth
            if (!node->left && !node->right)
                return depth;

            if (node->left)
                q.push({node->left, depth + 1});
            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0; // Just for safety, though this will never be hit
    }
};