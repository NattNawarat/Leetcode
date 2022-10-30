class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int cnt[coins.size()][amount+1];
        int i,j;
        for(i = 0 ; i < coins.size(); i++)
        {
            for(j = 0; j <= amount; j++ ){
                cnt[i][j] = 0;
                if(j == 0) cnt[i][j] = 1;
            }
        }
        for(i = 0 ; i < coins.size(); i++)
        {
            int curr_coin = coins.at(i);
            for(j = 1; j <= amount; j++ ){
                //printf("%d %d %d\n",i,j,amount);
                // add previous way
                if(i > 0){
                    cnt[i][j] += cnt[i-1][j];
                }
                // add way by adding its own coins
                if(j-curr_coin >= 0)
                {
                    cnt[i][j] += cnt[i][j-curr_coin];
                }
                //printf("%d ",cnt[i][j] );
            }
            //printf("\n");
        }
        
        return cnt[coins.size()-1][amount];
    }
    
};