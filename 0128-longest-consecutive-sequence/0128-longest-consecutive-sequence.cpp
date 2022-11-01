class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for(int i = 0 ; i < n ; i++){
            seen.insert(nums.at(i));
        }
        int count;
        int curr_num;
        int Ans = 0;
        for(int i = 0 ; i < n ; i++){
            if (!seen.count(nums.at(i)-1)){
                count = 0;
                curr_num = nums.at(i);
                while(seen.count(curr_num)){
                    curr_num += 1;
                    count +=1 ;
                }
                Ans = max(Ans,count);
                count = 0;
            }
        }
        return Ans;
    }
};