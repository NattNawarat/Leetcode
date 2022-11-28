class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> count(amount+1,-1);
        int n = amount,m = coins.size();
        for(int i = 0 ; i < m ;i++){
            if(coins.at(i)>n) continue;
            count.at(coins.at(i)) = 1;
        }
        
        count.at(0) = 0;
        for(int i = 0; i <= n; i++){
            if(count.at(i) == -1){
                continue;
            }
            int curr_coin_used = count.at(i);
            for(int j = 0; j < m ;j++){
                
                int curr_coin = coins.at(j);
                if(curr_coin > amount+1) continue;
                int curr_price = i;
                int target_price = curr_price + curr_coin;
                if (target_price <= amount){
                    if (count.at(target_price) == -1){ 
                        count.at(target_price) = curr_coin_used + 1;
                    } else {
                        count.at(target_price) = min(curr_coin_used + 1,count.at(target_price));
                    }
                }
            }
        }
        return count.at(amount);
    }
};