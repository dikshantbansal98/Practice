class Solution {
public:
    int minimumTime(string s) {
        int max_sum = 0, sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            int value = s[i] == '1'? -1:1;
            sum += value;
            max_sum = max(max_sum,sum);
            if(sum < 0)
                sum = 0;
        }
        return s.size() - max_sum;
    }
};