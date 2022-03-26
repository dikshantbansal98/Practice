class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int>result(tasks.size());
        set<pair<int,int>>busy,available;
        for(int i = 0; i < servers.size(); ++i) {
            available.insert({servers[i],i});
        }
        int previousTime = 0;
        for(int i = 0; i < tasks.size(); ++i) {
            int time = max(i, previousTime);
            if(available.size() == 0) {
                time = max(time, busy.begin()->first);
            }
            previousTime = time;
            while(busy.size() && busy.begin()->first<=time) {
                auto [availableTime,index] = *busy.begin();
                available.insert({servers[index],index});
                busy.erase(busy.begin());
            }
            auto [weight, index] = *available.begin();
            available.erase(available.begin());
            busy.insert({time+tasks[i],index});
            result[i]=index;
        }
        return result;
    }
};