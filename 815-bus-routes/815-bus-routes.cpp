class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        unordered_map<int,vector<int>> routeList;
        int bus = 0;
        for(auto &busPath: routes)
        {
            for(int path: busPath)
                routeList[path].push_back(bus);

            bus++;
        }
        queue<pair<int,int>>q;
        vector<bool>visited(routes.size());
        vector<vector<int>>adj(routes.size());
        for(auto [path,buses]:routeList)
        {
            for(int i = 0; i < buses.size(); ++i)
                for(int j = 0; j < buses.size(); ++j)
                    if(buses[i]-buses[j])
                        adj[buses[i]].push_back(buses[j]), adj[buses[j]].push_back(buses[i]);
        }
        for(auto bus: routeList[source])
        {
            q.push({bus,1});
            visited[bus] = true;
        }
        while(!q.empty())
            {
                auto [bus,dist] = q.front(); q.pop();
                if(count(routes[bus].begin(),routes[bus].end(), target))
                    return dist;
                for(auto bu:adj[bus])
                {
                    if(!visited[bu])
                    {
                        visited[bu] = true;
                        q.push({bu,dist+1});
                    }
                }
            }
            return -1;

    }
};