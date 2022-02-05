class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>charIndexes(26);
        for(int i = 0; i < s.size(); ++i) {
            charIndexes[s[i]-'a'].push_back(i);
        }
        int matchingWords = 0;
        for(string &word: words) {
            int i = 0, j = 0;
            for(j = 0; j < word.size(); ++j) {
                auto &indexesArray = charIndexes[word[j]-'a'];
                auto position = lower_bound(indexesArray.begin(),indexesArray.end(),i);
                if(position == indexesArray.end()) {
                    break;
                }
                i = *position+1;
            }
            if(j == word.size()) {
                matchingWords++;
            }
        }
        return matchingWords;
    }
};