bool compare(unordered_map<char,int>&freqS, unordered_map<char,int>&freqT)
{
    for(auto freq: freqT)
        if(freq.second>freqS[freq.first])
            return false;
    
    return true;
}
class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>freqS, freqT;
        for(char &ch:t)
            freqT[ch]++;
        int start = 0, ans_start = -1, min_length = 1e9;
        for(int i = 0; i < s.size(); ++i)
        {
            freqS[s[i]]++;
            while(compare(freqS, freqT))
            {
                if(i-start+1<min_length)
                {
                    min_length = i-start+1;
                    ans_start = start;
                }
                freqS[s[start]]--;
                if(freqS[s[start]] == 0) {
                    freqS.erase(s[start]);
                }
                start++;
            }
        }
        if(ans_start == -1)
            return "";
        else return s.substr(ans_start,min_length);
    }
};