class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        /*if(target < nums.at(0)){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else if(target > nums.at(n-1)){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }*/
        int begin_pos = 0;
        int end_pos = n-1;
        int mid_pos = begin_pos + (end_pos - begin_pos) / 2;
        //printf("%d %d %d\n",begin_pos,mid_pos,end_pos);
        int index = -1;
        while( begin_pos <= end_pos ){
            if(nums.at(mid_pos) == target) index = mid_pos;
            if(nums.at(mid_pos) < target){
                begin_pos = mid_pos+1;
                mid_pos = begin_pos + (end_pos - begin_pos) / 2;
            }
            else{
                end_pos = mid_pos-1;
                mid_pos = begin_pos + (end_pos - begin_pos) / 2;
            }
        }
        ans.push_back(index);
        begin_pos = 0;
        end_pos = n-1;
        mid_pos = begin_pos + (end_pos - begin_pos) / 2;
        index = -1;
        while( begin_pos <= end_pos ){
            if(nums.at(mid_pos) == target) index = mid_pos;
            if(nums.at(mid_pos) <= target){
                begin_pos = mid_pos+1;
                mid_pos = begin_pos + (end_pos - begin_pos) / 2;
            }
            else{
                end_pos = mid_pos-1;
                mid_pos = begin_pos + (end_pos - begin_pos) / 2;
            }
        }
        ans.push_back(index);
        return ans;
    }
};