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

// servers = [3,3,2] - weights of each server
// tasks = [1,2,3,2,1,2] - time needed to process
// At jth second jth task is inserted in queue
// task is assigned to free server with (smallest weight, smallest index)
    
// busy - , (5time,0), (5time,2), (5time,1)
// available - (3,1)
    
// 2,2,0,2,1