class Solution {
public:
    vector<vector<int>>dp;
    bool checkValidString(string s) {
       int lo = 0, hi = 0;
       for (char &c: s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) return false;
           lo = max(lo,0);
       }
       return lo <= 0;
    }
};