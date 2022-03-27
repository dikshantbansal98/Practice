class Solution {
public:
    int newInteger(int n) {
        string ans = "";
        while(n > 0) {
            ans = (char)('0'+n%9)+ans;
            n/=9;
        }
        return stoi(ans);
    }
};