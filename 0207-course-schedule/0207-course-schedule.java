class Solution {
    enum nodeStatus {
        WHITE,
        GRAY,
        BLACK
    }
    private List<nodeStatus> nodeStatuses = new ArrayList<>();
    private List<List<Integer>> edge = new ArrayList<>();
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        // create edge
        for (int i = 0; i < numCourses; i++) {
            edge.add(new ArrayList());
            nodeStatuses.add(nodeStatus.WHITE);
        }
        for(int[] courseRequirement : prerequisites){
            edge.get(courseRequirement[0]).add(courseRequirement[1]);
        }

        // find cycle
        for (int i = 0; i < numCourses; i++) {
            if(nodeStatuses.get(i) == nodeStatus.WHITE){
                if(findCycle(i)){
                    return false;
                }
            }

        }
        return true;
    }
    private boolean findCycle(int currentNode){
        //System.out.println(String.format("%d %s",currentNode,nodeStatuses.get(currentNode)));
        if (nodeStatuses.get(currentNode) == nodeStatus.BLACK){
            return false;
        }
        if(nodeStatuses.get(currentNode) == nodeStatus.GRAY){
            return true;
        }
        //System.out.println("Set to GRAY");
        nodeStatuses.set(currentNode,nodeStatus.GRAY);

        for(Integer nextNode : edge.get(currentNode)){
            if(findCycle(nextNode)){
                return true;
            }
        }
        //System.out.println("Set to BLACK");
        nodeStatuses.set(currentNode,nodeStatus.BLACK);

        return false;
    }
}