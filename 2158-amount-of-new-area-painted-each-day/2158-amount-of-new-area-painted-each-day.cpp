class Solution {
public:
    map<int,int>hash;
    int overLapAmount(pair<int,int>segment1, pair<int,int>segment2) {
        if(segment1.first >= segment2.second || segment2.first >= segment1.second) {
            return 0;
        }
        return min(segment1.second,segment2.second) - max(segment1.first,segment2.first);
    }
    
    pair<int,int> merge(pair<int,int>segment1, pair<int,int>segment2) {
        return {min(segment1.first,segment2.first), max(segment1.second,segment2.second)};
    }
    
    vector<int> amountPainted(vector<vector<int>>& paints) {
        vector<int>result;
        for(vector<int>&paint: paints) {
            int amount = 0;
            auto position = hash.upper_bound(paint[0]);
            if(position != hash.begin()) {
                position = prev(position);
            }
            int start = paint[0], end = paint[1];
            while(position!=hash.end() && position->first < paint[1]) {
                int overlap = overLapAmount({paint[0],paint[1]}, *position);
                if(overlap > 0) {
                    amount += overlap;
                    auto [first,second] = merge({start,end}, *position);
                    start = first, end = second;
                    auto copyIterator = position;
                    hash.erase(copyIterator);
                }
                position++;
            }
            hash[start] = end;
            result.push_back(paint[1]-paint[0]-amount);
        }
        return result;
    }
};