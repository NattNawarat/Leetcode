class Solution {
public:
    int getMatrixVal(vector<vector<int>>& matrix,int index, int m){
        int i = index / m;
        int j = index % m;
        return matrix.at(i).at(j);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n,m;
        n = matrix.size();
        m = matrix.at(0).size();
        //cout << endl;
        // begin binary search
        int start,end;
        start = 0;
        end = (n*m)-1;
        int index = (start+end)/2;
        //cout<<"start"<<endl;
        while (end-start >1){
            index = (start+end)/2;
            int curr_val = getMatrixVal(matrix,index,m);
            //cout<< curr_index<< " " <<start<<" "<<end<<endl ;
            if ((getMatrixVal(matrix,start,m) == target) || (getMatrixVal(matrix,end,m)== target)) return true;
            if (curr_val > target) end = index;
            if (curr_val < target) start = index;
            if (curr_val == target) return true;
        }
        if ((getMatrixVal(matrix,start,m) == target) || (getMatrixVal(matrix,end,m) == target)){
            return true;
        }
        else {
            return false;
        }
    }
};