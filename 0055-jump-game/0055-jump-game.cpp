class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        bool reachable[nums.size()];
        for(int i = 0 ; i < nums.size(); i++){
            reachable[i] = false;
        }

        reachable[0] = true;

        for(int i = 0 ; i < nums.size(); i++){
            if(reachable[i] == false)continue;
            jump = nums[i];
            for(int j = i+1 ; j <= i+jump ; j++)
            {
                if (j >= nums.size())break;
                reachable[j] = true;
            }
        }
    return reachable[nums.size()-1];
    }
};