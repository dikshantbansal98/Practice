class Solution {
public:
    vector<vector<int>>adj;
    vector<int>val;
    void dfs(int u)
    {
        vector<int>which(5,0);
        for(auto it:adj[u])
        {
            if(val[it]!=-1)
                which[val[it]]++;
        }
        for(int i=1;i<=4;++i)
            if(which[i]==0)
            {
                val[u]=i;
                break;
            }
        for(auto it:adj[u])
            if(val[it]==-1)
                dfs(it);
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        adj.resize(N+1);val.resize(N,-1);
        for(int i=0;i<paths.size();++i)
            adj[paths[i][0]-1].push_back(paths[i][1]-1),
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        for(int i=0;i<N;++i)
            if(val[i]==-1)
                dfs(i);
        return val;
        
    }
};