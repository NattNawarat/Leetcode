class Solution {
    public int[] productExceptSelf(int[] nums) {
            int n = nums.length;
            int[] prefixProduct = new int[n];
            int[] suffixProduct = new int[n];

            for(int i = 0 ; i<n;i++){
                if(i==0){
                    prefixProduct[i] = nums[i];
                    suffixProduct[n-i-1] = nums[n-i-1];
                } else {
                    prefixProduct[i] = prefixProduct[i-1] * nums[i];
                    suffixProduct[n-i-1] = suffixProduct[n-i] * nums[n-i-1];
                }
            }
        
        

            int[] answer = new int[n];
            answer[0] = suffixProduct[1];
            answer[n-1] = prefixProduct[n-2];
            for(int i = 1 ; i<n-1 ;i++){
                answer[i] = prefixProduct[i-1] * suffixProduct[i+1]; 
            }
            return answer;
    }
}