class Solution {
public:
    int find_length(string s, int l,int r){
        int n = s.length();
        while(l >= 0 && r < n){
            if (s[l] == s[r]){
                l--;
                r++;
            }
            else{
                break;
            }
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int center_point = 0;
        int max_len = 0;
        int l = 0;
        for(int i = 0 ; i <= n ;i++){
            int len = max(find_length(s,i,i),find_length(s,i,i+1));
            if (len > max_len){
                max_len = len;
                l = i - (len - 1) / 2;
            }
        }
        return s.substr(l,max_len);
    }
};