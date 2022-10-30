class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        dp.at(0) = 1;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++ ){
                dp.at(j) += dp.at(j-1);
            }
            for (int x : dp) cout << x << " ";
        }
        return dp.at(n-1);
    }
};