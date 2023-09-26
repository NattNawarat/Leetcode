class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> valuePostion = new HashMap();
        int n = nums.length;
        for(int i = 0 ; i < n ; i++){
            if(valuePostion.get(target-nums[i])!=null){
                return new int[]{valuePostion.get(target-nums[i]),i};
            }
            valuePostion.put(nums[i],i);
        }
        return new int[0];
    }
}