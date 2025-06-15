// Sum Root to Leaf Numbers (#129)

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        // We'll use a helper function with a queue (BFS-like idea)
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int totalSum = 0;

        while (!q.empty()) {
            auto [node, currVal] = q.front();
            q.pop();

            // If it's a leaf, add the number to total sum
            if (!node->left && !node->right) {
                totalSum += currVal;
            }

            // If left child exists, build new number and add to queue
            if (node->left) {
                q.push({node->left, currVal * 10 + node->left->val});
            }

            // If right child exists, build new number and add to queue
            if (node->right) {
                q.push({node->right, currVal * 10 + node->right->val});
            }
        }

        return totalSum;
    }
};