class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int,int>> BFS;//(index,jumps)
        BFS.push(make_pair(0,0));
        pair<int,int> curr_node;
        int ans = 0;
        bool visit[n];
        for(int i = 0 ; i < n ;i++){
            visit[i] = false;
        }
        if(n==1) return 0;
        while(!BFS.empty()){
            curr_node = BFS.front();
            BFS.pop();
            int curr_pos = curr_node.first;
            if(visit[curr_pos]) continue;
            int jump_length = nums[curr_pos];
            int number_of_jump = curr_node.second;
            visit[curr_pos] = true;
            if(curr_pos + jump_length >= n-1)
            {
                ans = number_of_jump+1;
                break;
            }
            for(int i = curr_pos+1; i <= curr_pos + jump_length;i++){
                BFS.push(make_pair(i,number_of_jump+1));
            }
        }
        return ans;
    }
};