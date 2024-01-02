class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> dist = new PriorityQueue<>((a,b)-> sqrDist(b)-sqrDist(a));
        for(int i = 0 ; i < points.length ; i++){
            dist.add(points[i]);
            if(dist.size() > k){
                dist.poll();
            }
        }
        int[][] ans = new int[k][2];
        int i = k;
        while (!dist.isEmpty())
        ans[--i] = dist.poll();

        return ans;
    }
    
    public int sqrDist(int[] point){
        return point[0]*point[0] + point[1]*point[1];
    }
}