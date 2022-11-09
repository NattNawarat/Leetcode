class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            int min = 301;
            int index = i;
            for (int j = i ; j < n;j++){
                if (nums.at(j) < min){
                    min = nums.at(j);
                    index = j;
                }
            }
            if(index != i){
                    swap(nums.at(i),nums.at(index));
            }
        }
    }
};