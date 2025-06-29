// Search in a Binary Search Tree (#700)

Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

 class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // If the tree is empty or we've found the value
        if (root == null || root.val == val) {
            return root;
        }

        // If the value is smaller, go left
        if (val < root.val) {
            return searchBST(root.left, val);
        }

        // If the value is larger, go right
        return searchBST(root.right, val);
    }
}