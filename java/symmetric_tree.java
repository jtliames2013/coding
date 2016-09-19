/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left==null && right==null) return true;
        else if (left==null || right==null) return false;
        else {
            return left.val==right.val && isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
        }
    }
    
    public boolean isSymmetric(TreeNode root) {
        if (root==null) return true;
        return isSymmetric(root.left, root.right);
    }
}
