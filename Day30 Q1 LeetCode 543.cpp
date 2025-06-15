// Diameter of Binary Tree (#543)

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
    int maxDiameter = 0; // Stores the maximum diameter found

    // Helper function to calculate height and update diameter
    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Recursively find the height of left and right subtrees
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        // Update the diameter at this node if the path through it is longer
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};