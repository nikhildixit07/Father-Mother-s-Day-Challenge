// Flatten Binary Tree to Linked List (#114)

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        std::stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = nullptr;

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            // If there's a previous node, point its right to current
            if (prev) {
                prev->left = nullptr;    // Left should always be null
                prev->right = curr;
            }

            // Since stack is LIFO, push right first so left is processed first
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            // Move to the next node
            prev = curr;
        }
    }
};