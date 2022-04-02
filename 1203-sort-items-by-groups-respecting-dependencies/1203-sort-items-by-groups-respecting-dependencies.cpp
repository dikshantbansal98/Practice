
class Solution {
public:
vector<vector<int>>adjG, adj;
vector<int>order, orderG,vis,visG, group;
int timer;
    vector<int> sortItems(int n, int m, vector<int>& gr, vector<vector<int>>& beforeItems)       {
        timer = 0;
        for(int &i:gr)
            if(i==-1)
                i = m++;
        group = gr;
        adjG.resize(m+1);visG.resize(m+1);
        adj.resize(n); vis.resize(n);
        for(int i = 0; i < n; ++i)
            for(auto edge:beforeItems[i])
            {
                if(group[edge]!=group[i])
                adjG[group[i]].push_back(group[edge]); 
                else
                adj[i].push_back(edge);
            }
        for(int i = 0; i < m; ++i)
        {
            if(!dfs(i,orderG,adjG,visG))
                return vector<int>{};
        }

        for(int i = 0; i < n; ++i)
        {
            if(!dfs(i,order,adj,vis))
                return vector<int>{};
        }
        map<int,vector<int>>map1;
        vector<int>ans;
        for(auto item: order)
        {
            map1[group[item]].push_back(item);
        }
        for(auto gr: orderG)
        {
            for(auto it:map1[gr])
                ans.push_back(it);
        }
        return ans;
    }
    bool dfs(int u, vector<int>&ord, vector<vector<int>>&G, vector<int>&visited)
    {
        
        if(visited[u]>0)
            return visited[u] == 2;
        visited[u] = 1;
        for(auto it:G[u])
        {
            if(!dfs(it,ord,G,visited))
                return false;
        }
        ord.push_back(u);
        visited[u] = 2;
        return true;
    }
    
};