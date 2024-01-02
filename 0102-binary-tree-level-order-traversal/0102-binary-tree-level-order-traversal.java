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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList();
        Queue<Pair<TreeNode,Integer>> BFSQueue = new LinkedList<>();
        
        if(root != null){
            BFSQueue.add(new Pair<TreeNode,Integer>(root,1));
        }
                     
        while(!BFSQueue.isEmpty()){
            Pair<TreeNode,Integer> nodePair = BFSQueue.remove();
            Integer level = nodePair.getValue();
            TreeNode currentNode = nodePair.getKey();
            
            addNodeToAns(level, currentNode.val, ans);
            
            if(currentNode.left != null){
                BFSQueue.add(new Pair<TreeNode,Integer>(currentNode.left,level+1));
            }
            if(currentNode.right != null){
                BFSQueue.add(new Pair<TreeNode,Integer>(currentNode.right,level+1));
            }
        }
        return ans;
    }
                     
    private void addNodeToAns(Integer level, int nodeVal, List<List<Integer>> ans){
        if(ans.size() < level){
            ans.add(new ArrayList());
        }
        ans.get(level-1).add(nodeVal);
    }
}