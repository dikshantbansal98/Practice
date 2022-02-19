class Solution {
public:
    set<string>set;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>result;
        sort(words.begin(),words.end(), [](const string &a, const string &b){
            return a.size()<b.size();
        });
        
        for(string &word: words) {
            if(word == "") {
                continue;
            }
            vector<vector<bool>>dp(word.size(),vector<bool>(word.size()));
            for(int i = 0; i < word.size(); ++i) {
                string str = "";
                for(int j = i; j < word.size(); ++j) {
                    str += word[j];
                    if(set.find(str)!=set.end()) {
                        dp[i][j] = true;
                    }
                }
            }
            vector<bool>dp2(word.size());
            for(int i = 0; i < word.size(); ++i) {
                if(dp[0][i]) {
                    dp2[i] = true;
                    continue;
                }
                for(int j = 0; j < i; ++j) {
                    if(dp2[j] && dp[j+1][i]) {
                        dp2[i] = true;
                        break;
                    }
                }
            }
            if(dp2[word.size()-1]) {
                result.push_back(word);
            }
            set.insert(word);
        }
        return result;
    }
};