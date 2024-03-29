/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        travel(root);
        return root;
    }
    
    private void travel(TreeNode node){
        if(node == null){
            return;
        }
        if(node.left == null && node.right == null){
            return;
            
        }
        travel(node.left);
        travel(node.right);
        switchLeafNode(node);
        
    }
    private void switchLeafNode(TreeNode node){
            TreeNode tempNode = node.left;
            node.left = node.right;
            node.right = tempNode;
    }
}