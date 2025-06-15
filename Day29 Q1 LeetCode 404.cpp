// Sum of Left Leaves (#404)

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
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case: if the root is null, return 0
        if (!root) return 0;

        int sum = 0;

        // Check if the left child exists and is a leaf node
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val; // Add left leaf value to sum
        }

        // Recursively call for left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};