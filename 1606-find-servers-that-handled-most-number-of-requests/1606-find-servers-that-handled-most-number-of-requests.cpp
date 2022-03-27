class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>available = getSet(k);
        map<int,int>frequencies;
        set<pair<int,int>>busy;
        for(int i = 0; i < arrival.size(); ++i) {
            int arrivalTime = arrival[i], loadTime = load[i];
            while(busy.size() && busy.begin()->first <= arrivalTime) {
                auto [availableTime, index] = *busy.begin();
                available.insert(index);
                busy.erase(busy.begin());
            }
            if(available.empty()) {
                continue;
            }
            int position = i%k;
            auto pos = available.lower_bound(position);
            if(pos == available.end()) {
                pos = available.begin();
            }
            position = *pos;
            frequencies[position]++;
            available.erase(pos);
            busy.insert({arrivalTime+loadTime, position});
        }
        return getResult(frequencies);
    }
    
    vector<int> getResult(map<int,int>&frequencies) {
        int maxFrequency = 0;
        vector<int>result;
        for(auto [value, frequency]: frequencies) {
            maxFrequency = max(maxFrequency, frequency);
        }
        for(auto [value, frequency]: frequencies) {
            if(frequency == maxFrequency) {
                result.push_back(value);
            }
        }
        return result;
    }
    
    set<int> getSet(int k) {
        set<int>available;
        for(int i = 0; i < k; ++i) {
            available.insert(i);
        }
        return available;
    }
};


// ith request - ith server available - assign to i%k server

// available - set - indexes
// busy - set - (avalableTime,index)