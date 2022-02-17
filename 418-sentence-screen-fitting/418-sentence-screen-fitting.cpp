class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string completeSentence = "";
        for(string &word: sentence) {
            completeSentence += word + ' ';
        }
        vector<int>dp(completeSentence.size());
        for(int i = 1; i < completeSentence.size(); ++i) {
            if(completeSentence[i] == ' ') {
                dp[i] = 1;
            }
            else {
                dp[i] = dp[i-1] - 1;
            }
        }
        int placedChars = 0;
        int sentenceSize = completeSentence.size();
        for(int i = 0; i < rows; ++i) {
            placedChars += cols;
            placedChars += dp[placedChars%sentenceSize];
        }
        return placedChars/sentenceSize;
    }
};