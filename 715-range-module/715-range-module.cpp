class RangeModule {
public:
    map<int,int>ranges;
    RangeModule() {
        
    }
    
    void printMap() {
        for(auto [key,value]: ranges) {
            cout<<key<<" "<<value<<endl;
        }
    }
    
    void addRange(int left, int right) {
        auto position = ranges.upper_bound(left);
        if(position != ranges.begin()) {
            position--;
        }
        int start = left, end = right;
        while(position != ranges.end() && position->first <= right) {
            if(position->second<start) {
                position++;
                continue;
            }
            start = min(start, position->first);
            end = max(end, position->second);
            ranges.erase(position++);
        }
        ranges[start] = end;
        //printMap();
    }
    
    bool queryRange(int left, int right) {
        auto position = ranges.upper_bound(left);
        if(position != ranges.begin()) {
            position--;
        }
        else {
            return false;
        }
        return position->first <= left && position->second>=right;
    }
    
    void removeRange(int left, int right) {
        auto position = ranges.upper_bound(left);
        if(position != ranges.begin()) {
            position--;
        }
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
        //printMap();
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