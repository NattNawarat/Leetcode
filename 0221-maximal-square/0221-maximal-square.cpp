class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix.at(0).size();
        int count[300][300];
        int Max = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m ;j++){
                count[i][j] = matrix.at(i).at(j)-'0';
                if (count[i][j] == 1) {
                    if (i >= 1 && j >= 1){
                        int min_square_size = 400;
                        if(count[i-1][j-1] < min_square_size) min_square_size = count[i-1][j-1];
                        if(count[i][j-1] < min_square_size) min_square_size = count[i][j-1];
                        if(count[i-1][j] < min_square_size) min_square_size = count[i-1][j];
                        count[i][j] = min_square_size + 1;
                    }
                
                }
                if(count[i][j] > Max) Max = count[i][j];
            }
        }
        return Max*Max;
    }
};