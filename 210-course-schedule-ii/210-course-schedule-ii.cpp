class Solution {
    vector<vector<int>>adj;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vector<int>ans;
        vector<int>indegree(numCourses);
        for(auto dependency:prerequisites)
        {
            adj[dependency[1]].push_back(dependency[0]);
            indegree[dependency[0]]++;
        }
        queue<int>q;
        
        for(int i = 0; i < indegree.size(); ++i)
            if(indegree[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                int start = q.front(); q.pop();
                ans.push_back(start);
                for(auto destination:adj[start])
                {
                    if(--indegree[destination] == 0) q.push(destination);
                }
            }
        }
        if(ans.size() == numCourses)
            return ans;
        ans.clear();
        return ans;
    }
};