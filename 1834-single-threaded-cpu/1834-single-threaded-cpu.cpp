class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>order;
        if(tasks.size() == 0) {
             return order;
        }
        vector<pair<int,pair<int,int>>>tasksArray;
        for(int i = 0; i < tasks.size(); ++i) {
            tasksArray.push_back({tasks[i][0], {tasks[i][1], i}});
        }
        sort(tasksArray.begin(),tasksArray.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        int index = 0;
        long long time = 0;
        while(order.size() != tasks.size()) {
            if(pq.empty() && index < tasksArray.size()) {
                auto [entryTime, taskMetadata] = tasksArray[index];
                auto [executionTime, taskNumber] = taskMetadata;
                time = max(time,(long long)entryTime);
            }
            while(index<tasksArray.size() && tasksArray[index].first <= time) {
                auto [entryTime, taskMetadata] = tasksArray[index++];
                auto [executionTime, taskNumber] = taskMetadata;
                pq.push({executionTime, taskNumber});
            }
            auto [executionTime, taskNumber] = pq.top();
            pq.pop();
            time += executionTime;
            order.push_back(taskNumber);
        }
        return order;
    }
};