class Solution {
public:
    int minimumTime(string s) {
        int max_sum = 0, sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            int value = s[i] == '1'? -1:1;
            sum = max(sum+value, 0);
            max_sum = max(max_sum,sum);
        }
        return s.size() - max_sum;
    }
};