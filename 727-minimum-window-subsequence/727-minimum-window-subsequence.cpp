class Solution {
public:
    string minWindow(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        for(int i = 0; i < s1.size(); ++i) {
            for(int j = 0; j < s2.size(); ++j) {
                if(j == 0) {
                    if(s1[i] == s2[j]){
                        dp[i][j] = i;
                    }
                    else if(i){
                        dp[i][j] = dp[i-1][j];
                    }
                    continue;
                }
                if(i == 0) {
                    continue;
                }
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int start = -1, length = 1e8;
        for(int i = 0; i < s1.size(); ++i) {
            if(dp[i].back()!=-1) {
                if(i-dp[i].back()+1<length) {
                    length = i-dp[i].back()+1;
                    start = dp[i].back();
                }
            }
        }
        if(start == -1) {
            return "";
        }
        return s1.substr(start,length);
    }
};

//     b d e
// a   n n n
// b   1 n n
// c   1 n n
// d   1 1 n
// e   1 1 1
// b   5 1 1
// d   5 5 1
// e   5 5 5