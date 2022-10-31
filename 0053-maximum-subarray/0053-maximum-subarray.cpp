class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int Max = -1000000;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            curr_sum += nums.at(i);
            Max = max(Max,curr_sum);
            if (curr_sum < 0) curr_sum = 0;
        }
    return Max;
    }
};