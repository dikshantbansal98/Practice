class Solution {
public:
    int minFlips(string s) {
        vector<int>odds(2),evens(2);
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(i%2) {
                odds[s[i]-'0']++;
            }
            else {
                evens[s[i]-'0']++;
            }
        }
        int ans = min(odds[1]+evens[0],odds[0]+evens[1]);
        for(int i = 0; i < n ; ++i) {
            swap(evens,odds);
            odds[s[i]-'0']--;
            if((n-1)%2) {
                odds[s[i]-'0']++;
            }
            else {
                evens[s[i]-'0']++;
            }
            ans = min({ans,odds[1]+evens[0],odds[0]+evens[1]});
        }
        return ans;
    }
};
