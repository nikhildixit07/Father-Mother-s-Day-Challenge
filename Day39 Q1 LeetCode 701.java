// Insert into a Binary Search Tree (#701)

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // If the tree is empty, create a new node and return it as root
        if (root == null) {
            return new TreeNode(val);
        }

        // If value is less, go to the left subtree
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } 
        // If value is greater, go to the right subtree
        else {
            root.right = insertIntoBST(root.right, val);
        }

        // Return the unchanged root
        return root;
    }
}