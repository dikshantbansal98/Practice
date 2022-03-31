class Solution {
public:
    vector<vector<int>>adj;
    vector<vector<int>>gcd;
    int n;
    vector<int>ans;
    vector<int>arr;
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        gcd = vector<vector<int>>(51);
        for(int i = 1; i <= 50; ++i)
            for(int j = 1; j <= 50; ++j)
            {
                if(__gcd(i,j) == 1)
                    gcd[i].push_back(j);
            }
        adj.resize(n);
        ans = vector<int>(n,-1);
        arr = nums;
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>indexes(51,-1), levels(51,0);
        dfs(0,-1,indexes,levels);
        return ans;
    }
    void dfs(int u, int p, vector<int>indexes, vector<int>levels, int l = 0)
    {
        int maxLevel = -1;
        for(int &num:gcd[arr[u]]) {
            if(indexes[num]!=-1 && levels[num]>maxLevel) {
                maxLevel = levels[num];
                ans[u] = indexes[num];
            }
        }
        indexes[arr[u]] = u;
        levels[arr[u]] = l;
        for(auto it:adj[u])
            if(it-p)
                dfs(it,u,indexes,levels,l+1);
    }
};