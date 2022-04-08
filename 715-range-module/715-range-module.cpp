class RangeModule {
public:
    map<int,int>ranges;
    RangeModule() {}
    
    map<int,int>::iterator getPosition(int left, int right) {
        auto position = ranges.upper_bound(left);
        if(position != ranges.begin()) {
            position--;
        }
        if(position != ranges.end() && position->second < left) {
            position++;
        }
        return position;
    }
    
    void addRange(int left, int right) {
        int start = left, end = right;
        auto position = getPosition(start, end);
        while(position != ranges.end() && position->first <= right) {
            start = min(start, position->first);
            end = max(end, position->second);
            ranges.erase(position++);
        }
        ranges[start] = end;
    }
    
    bool queryRange(int left, int right) {
        auto position = getPosition(left, right);
        return position!=ranges.end() && position->first <= left && position->second>=right;
    }
    
    void removeRange(int left, int right) {
        auto position = getPosition(left, right);
        vector<pair<int,int>>pairs;
        while(position != ranges.end() && position->first < right) {
            auto pair = *position;
            if(pair.second < left) {
                position++;
                continue;
            }
            if(pair.first<left) {
                pairs.push_back({pair.first,left});
            }
            if(pair.second>right) {
                pairs.push_back({right,pair.second});
                ranges[right] = pair.second;
            }
            ranges.erase(position++);
        }
        for(auto [x,y]:pairs) {
            ranges[x] = y;
        }
    }
    
    pair<int,int> merge(pair<int,int>point1, pair<int,int>point2) {
        return {min(point1.first,point2.first),max(point1.second,point2.second)};
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */