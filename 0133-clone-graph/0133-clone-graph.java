/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null){
            return null;
        }
        Queue<Node> BFSQueue = new ArrayDeque<>();
        Map<Node,Node> nodeReference = new HashMap<>();
        BFSQueue.add(node);
        nodeReference.put(node,new Node(node.val));
        while(!BFSQueue.isEmpty()){
            Node originalNode = BFSQueue.poll();
            Node cloneNode =  nodeReference.get(originalNode);
            for(Node neighbor : originalNode.neighbors){
                if(!nodeReference.containsKey(neighbor)){
                    nodeReference.put(neighbor, new Node(neighbor.val));
                    BFSQueue.add(neighbor);
                }
                cloneNode.neighbors.add(nodeReference.get(neighbor));
            }
            
        }
        return nodeReference.get(node);
    }
}