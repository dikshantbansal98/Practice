class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string completeSentence = "";
        for(string &word: sentence) {
            completeSentence += word + ' ';
        }
        int sentenceSize = completeSentence.size();
        vector<int>dp(sentenceSize);
        for(int i = 1; i < sentenceSize; ++i) {
            if(completeSentence[i] == ' ') {
                dp[i] = 1;
            }
            else {
                dp[i] = dp[i-1] - 1;
            }
        }
        int placedChars = 0;
        for(int i = 0; i < rows; ++i) {
            placedChars += cols;
            placedChars += dp[placedChars%sentenceSize];
        }
        return placedChars/sentenceSize;
    }
};
/*
//  h  e  l  l  o   w  o  r  l  d
//  0 -1 -2 -3 -4 1 0 -1 -2 -3  -4
    0  1  2  3  4 5 6  7  8  9  10

//sentenceSize = 12

//placedChars = 14
*/