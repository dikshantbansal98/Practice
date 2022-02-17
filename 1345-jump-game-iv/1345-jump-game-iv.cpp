class Solution {
public:
    int minJumps(vector<int>& arr) {
        int ans = 0;
        map<int,set<int>>indexes;
        for(int i = 0; i < arr.size(); ++i) {
            indexes[arr[i]].insert(i);
        }
        vector<bool>visited(arr.size());
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0] = true;
        while(!q.empty()) {
            auto [index, steps] = q.front(); q.pop();
            if(index == arr.size()-1) {
                return steps;
            }
            if(index>0 && !visited[index-1]) {
                q.push({index-1,steps+1});
                visited[index-1] = true;
            }
            if(index<arr.size()-1 && !visited[index+1]) {
                q.push({index+1,steps+1});
                visited[index+1] = true;
            }
            for(auto toIndex: indexes[arr[index]]) {
                if(!visited[toIndex]) {
                    visited[toIndex] = true;
                    q.push({toIndex, steps+1});
                    indexes[arr[index]].erase(toIndex);
                }
            }
        }
        return -1;
    }
};