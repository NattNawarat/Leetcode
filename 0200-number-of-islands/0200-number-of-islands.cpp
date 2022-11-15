class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.at(0).size();
        bool visit[n][m];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visit[i][j] = false;
            }
        }
        //travel
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ((!visit[i][j]) && (grid.at(i).at(j) == '1')){
                    queue<int> BFS_i;
                    queue<int> BFS_j;
                    BFS_i.push(i);
                    BFS_j.push(j);
                    count += 1;
                    
                    while(!BFS_i.empty()){
                        int curr_i = BFS_i.front();
                        int curr_j = BFS_j.front();
                        BFS_i.pop();
                        BFS_j.pop();
                        if(visit[curr_i][curr_j] == true)continue;
                        visit[curr_i][curr_j] = true;
                        if(curr_i+1 < n){
                            if((!visit[curr_i+1][curr_j]) && (grid.at(curr_i+1).at(curr_j) == '1')){
                                BFS_i.push(curr_i+1);
                                BFS_j.push(curr_j);
                            }
                        }
                        if(curr_j+1<m){
                            if((!visit[curr_i][curr_j+1]) && (grid.at(curr_i).at(curr_j+1) == '1')){
                                BFS_i.push(curr_i);
                                BFS_j.push(curr_j+1);
                            }
                        }
                        if(curr_i-1 >= 0){
                            if((!visit[curr_i-1][curr_j]) && (grid.at(curr_i-1).at(curr_j) == '1')){
                                BFS_i.push(curr_i-1);
                                BFS_j.push(curr_j);
                            }
                        }
                        if(curr_j-1 >= 0){
                            if((!visit[curr_i][curr_j-1]) && (grid.at(curr_i).at(curr_j-1) == '1')){
                                BFS_i.push(curr_i);
                                BFS_j.push(curr_j-1);
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};