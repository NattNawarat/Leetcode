class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> M_L(n,0);
        vector<int> M_R(n,0);
        vector<int> wall(n,0);
        int cnt = 0;
        for (int i = 0 ; i < n; i++){
            if(i==0){
                M_L.at(i) = height.at(i);
                M_R.at(n-1-i) = height.at(n-1-i);
            }
            else{
                M_L.at(i) = max(height.at(i),M_L.at(i-1));
                M_R.at(n-1-i) = max(height.at((n-1-i)),M_R.at(n-i));
            }
        }
        for (int i = 0 ; i < n; i++){
            printf("%d ",M_L.at(i));
        }
        printf("\n");
        for (int i = 0 ; i < n; i++){
            printf("%d ",M_R.at(i));
        }
        printf("\n");
        for (int i = 0 ; i < n; i++){
            wall.at(i) = min(M_L.at(i), M_R.at(i));
            printf("%d ",wall.at(i));
            if(i != 0 && i != n-1){
                cnt += wall.at(i) - height.at(i);
            }
        }
        return cnt;
    }
};