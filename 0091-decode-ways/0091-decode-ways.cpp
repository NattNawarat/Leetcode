class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        int count[n];
        if (s[0] != '0') count[0] = 1;
        else count[0] = 0;
        for(int i = 1 ; i < n ;i++)
        {
            //cout<<"index "<< i <<endl;
            // single digit
            count[i] = 0;
            if (s[i] - '0' > 0){
                //cout<< "single" << endl;
                count[i] += count[i-1];
            }
            
            //double digit

            int double_digit = stoi(s.substr(i-1,2));
            if(double_digit <= 26 && s[i-1] != '0'){
                //cout<< "double" << endl; 
                if(i == 1) count[i] += 1;
                else count[i] += count[i-2];
            }
            //cout << count[i] <<endl;   
        }
        return count[n-1];
    }
};


/*
226
1 2 3

22112

1
2

1 2
2 2
22

1 2 3
2 2 1
22 1
2 21

1 2 3 3+2
2 2 1 1
22 1 1
2 21 1
2 2 11
22 11


*/