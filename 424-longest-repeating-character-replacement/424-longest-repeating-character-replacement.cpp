class Solution {
public:
    unordered_map<char,int>frequency;
    int ans;
    int k;
    bool compare() {
        vector<int>freqs;
        for(auto [character, count] : frequency) {
            freqs.push_back(count);
        }
        sort(freqs.begin(), freqs.end());
        int value = freqs.back();
        int count = 0;
        for(int j = freqs.size()-2; j >= 0; --j) {
            count += freqs[j];
        }
        if(count <= k) {
            ans = max(ans,value+count);
        }
        return count <= k;
    }
    int characterReplacement(string s, int p) {
        k = p;
        ans = 0;
        int start = 0;
        for(int i = 0; i < s.size(); ++i) {
            frequency[s[i]]++;
            while(!compare()) {
                frequency[s[start]]--;
                if(frequency[s[start]] == 0) {
                    frequency.erase(s[start]);
                }
                start++;
            }
        }
        return ans;
    }
};