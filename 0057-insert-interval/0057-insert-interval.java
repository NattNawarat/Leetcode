class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        final int n = intervals.length;
        List<int[]> intervalList = new ArrayList<int[]>();
        boolean isAdd = false;
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0])
        {
            intervalList.add(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = Math.min(intervals[i][0],newInterval[0]);
            newInterval[1] = Math.max(intervals[i][1],newInterval[1]);
            i++;
        }
        intervalList.add(newInterval);
        while(i < n)
        {
            intervalList.add(intervals[i]);
            i++;
        }
        return intervalList.toArray(new int[0][]);
    }
    
}