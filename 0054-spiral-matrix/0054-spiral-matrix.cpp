class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.at(0).size();
        bool visit[n][m];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visit[i][j] = false;
            }
        }

        vector<int> answer;
        int count = 0;
        int curr_i = 0,curr_j = 0;
        int state = 0; // 0 go right,1 go down, 2 go left, 3 go up
        while(count < n*m){
            count++;
            int curr_val = matrix.at(curr_i).at(curr_j);
            answer.push_back(curr_val);
            visit[curr_i][curr_j] = true;
            //cout<< matrix.at(curr_i).at(curr_j) << " ";
            if (state == 0){
                // go right if you can else go down
                if(curr_j+1 >= m){
                    state = 1;
                    curr_i++;
                    continue;
                }
                else if(visit[curr_i][curr_j+1]){
                    state = 1;
                    curr_i++;
                    continue;
                }
                curr_j++;
                continue;
            }
            else if (state == 1){
                // go down if you can else go left
                if(curr_i+1 >= n){
                    state = 2;
                    curr_j--;
                    continue;
                }
                else if(visit[curr_i+1][curr_j]){
                    state = 2;
                    curr_j--;
                    continue;
                }
                curr_i++;
                continue;
            }
            else if (state == 2){
                // go left if you can else go up
                if(curr_j-1 < 0){
                    state = 3;
                    curr_i--;
                    continue;
                }
                else if(visit[curr_i][curr_j-1]){
                    state = 3;
                    curr_i--;
                    continue;
                }
                curr_j--;
                continue;
            }
            else if (state == 3){
                // go up if you can else go right
                if(curr_i-1 < 0){
                    state = 0;
                    curr_j++;
                    continue;
                }
                else if(visit[curr_i-1][curr_j]){
                    state = 0;
                    curr_j++;
                    continue;
                }
                curr_i--;
                continue;
            }
        }
        return answer;
    }
};