class Solution {
public:
    vector<string> ans;
    void addParenthesis(int l,int r, string s){
        string new_s;
        //cout<< l<<" "<<r<<" "<<s<<endl;
        if (l == 0 && r == 1 ){
            ans.push_back(s+")");
            return;
        }
        if (l > 0){
            new_s = s+"(";
            addParenthesis(l-1,r,new_s);        
        }
        if (r > l){
            new_s = s+")";
            addParenthesis(l,r-1,new_s);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        addParenthesis(n,n,"");

        return ans;
    }
};