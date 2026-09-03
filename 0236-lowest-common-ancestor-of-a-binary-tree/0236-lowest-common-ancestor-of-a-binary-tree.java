/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null){
            return null;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode leftAnswer=lowestCommonAncestor(root.left,p,q);
        TreeNode rightAnswer=lowestCommonAncestor(root.right,p,q);
        if(leftAnswer == null && rightAnswer == null){
            return null;
        }
        if(leftAnswer != null && rightAnswer == null){
            return leftAnswer;
        }
        if(leftAnswer == null && rightAnswer != null){
            return rightAnswer;
        }
        return root;
    }
}