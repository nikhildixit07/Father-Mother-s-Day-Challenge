// Maximum Depth of Binary Tree (#104)

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
    // Recursive DFS function to compute max depth
    int maxDepth(TreeNode* root) {
        if (!root) return 0;  // Base case: empty tree has depth 0

        // Recursively get the max depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is max of left/right + 1 (for the root)
        return 1 + max(leftDepth, rightDepth);
    }
};