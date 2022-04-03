class Solution {
public:
    bool isPossible(vector<int>& nums) {
        queue<int>q;
        vector<int>frequencies(2002);
        for(int &num:nums) {
            frequencies[num+1000]++;
        }
        for(int i = 1; i <= 2001; ++i) {
            int diff = frequencies[i]-frequencies[i-1];
            while(diff>0) {
                q.push(i);
                diff--;
            }
            while(diff<0) { 
                if(i-1-q.front()<2) {
                    return false;
                }
                q.pop();
                diff++;
            }
        }
        return true;
    }
};