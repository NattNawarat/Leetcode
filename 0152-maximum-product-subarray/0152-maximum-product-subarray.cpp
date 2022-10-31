class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max = nums.at(0);
        int n = nums.size();
        int curr_prod = nums.at(0);
        for(int i = 1 ; i < n ;i++){
            curr_prod *= nums.at(i);
            if (curr_prod == 0){
                curr_prod = nums.at(i);
                //Max = max(0,Max);
            }
            Max = max(curr_prod,Max);
        }
        curr_prod = nums.at(n-1);
        Max = max(Max,curr_prod);
        for(int i = n-2 ; i >= 0 ;i--){
            curr_prod *= nums.at(i);
            if (curr_prod == 0){
                curr_prod = nums.at(i);
                //Max = max(0,Max);
            }
            Max = max(curr_prod,Max);
        }
    return Max;
    }
};