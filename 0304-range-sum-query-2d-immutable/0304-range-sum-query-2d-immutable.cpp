class NumMatrix {
public:
    int n,m;
    int arr[200][200];
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix.at(0).size();
        // set base case
        for(int i = 0 ; i < n ; i++){
            if (i==0) arr[i][0] = matrix.at(i).at(0);
            else arr[i][0] = arr[i-1][0] + matrix.at(i).at(0);
        }
        for(int j = 0 ; j < m ; j++){
            if (j==0) arr[0][j] = matrix.at(0).at(j);
            else arr[0][j] = arr[0][j-1] + matrix.at(0).at(j);
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1] + matrix.at(i).at(j) - arr[i-1][j-1] ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << arr[i][j] << " ";
            }
            //cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up_sum,left_sum,intersec_sum;
        if (row1 == 0 or col1 == 0){
            intersec_sum = 0;
            if (row1 == 0) up_sum = 0;
            else up_sum = arr[row1-1][col2];
            
            if (col1 == 0) left_sum = 0;
            else left_sum = arr[row2][col1-1];
        }
        else{
            intersec_sum = arr[row1-1][col1-1];
            up_sum = arr[row1-1][col2];
            left_sum = arr[row2][col1-1];
        }
        //cout << arr[row2][col2] << " " << left_sum << " " << up_sum << " " <<intersec_sum << endl;
        int sum = arr[row2][col2] - left_sum - up_sum + intersec_sum;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */