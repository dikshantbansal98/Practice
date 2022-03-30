#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int n;
	vector<vector<pair<int, int>>>adj;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
    	n = N;
        adj.resize(n+1);
        for(auto &it:times)
        	adj[it[0]].push_back({it[2],it[1]});
        int ans = dij(K);
        if(ans==1000007)ans = -1;
        return ans;
    }
    int dij(int s)
    {
    	vector<int>dis(n+1,1000007);
    	dis[0] = dis[s] = 0;
    	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    	q.push({0,s});
    	while(!q.empty())
    	{
    		auto [distance,source] = q.top(); q.pop();
    		for(auto [weight,to]:adj[source])
    		{
    			if(dis[source]+weight<dis[to])
    			{
    				dis[to] = dis[source]+weight;
    				q.push({dis[to],to});
    			}
    		}
    	}
    	return *max_element(dis.begin(), dis.end());

    }
    
};