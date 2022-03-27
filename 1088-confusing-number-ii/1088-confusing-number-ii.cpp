class Solution {
public:
    unordered_map<int,int>hash = {{0,0},{1,1},{6,9},{8,8},{9,6}};
    int ans;
    int confusingNumberII(int n) {
        for(auto [key,_]: hash) {
            if(key) {
                dfs(key,n);
            }
        }
        return ans;
    }
    
    void dfs(long start, int &n) {
        if(start > n) {
            return;
        }
        if(start != getReverse(start)) {
            ans++;
        }
        for(auto [key,_]: hash) {
            dfs(start*10+key,n);
        }
        
    }
    long getReverse(long start) {
        string str = to_string(start);
        for(char &ch:str) {
            ch = '0' + hash[ch-'0'];
        }
        reverse(str.begin(),str.end());
        return stol(str);
    }
};