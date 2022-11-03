class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.at(0).size();
        for(int j = 1 ; j < m ; j++)grid.at(0).at(j) += grid.at(0).at(j-1);
        for(int i = 1 ; i < n ; i++)grid.at(i).at(0) += grid.at(i-1).at(0);
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ;j++){
                grid.at(i).at(j) += min(grid.at(i-1).at(j),grid.at(i).at(j-1));
                //printf("%d ",grid.at(i).at(j));
            }
            //printf("\n");
        }
        return grid.at(n-1).at(m-1);
    }
};