typedef tuple<int,int,int> type;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>order;
        if(tasks.size() == 0) {
             return order;
        }
        vector<type>tasksArray;
        for(int i = 0; i < tasks.size(); ++i) {
            tasksArray.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(tasksArray.begin(),tasksArray.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int index = 0;
        long long time = 0;
        while(order.size() != tasks.size()) {
            if(pq.empty() && index < tasks.size()) {
                auto [startTime, processingTime, number] = tasksArray[index++];
                pq.push({processingTime, number});
                time = max(time,(long long)startTime);
            }
            while(index < tasksArray.size() && time >= get<0>(tasksArray[index])) {
                auto [startTime, processingTime, number] = tasksArray[index++];
                pq.push({processingTime, number});
            }
            auto [processingTime, number] = pq.top(); pq.pop();
            time += processingTime;
            order.push_back(number);
        }
        return order;
    }
};