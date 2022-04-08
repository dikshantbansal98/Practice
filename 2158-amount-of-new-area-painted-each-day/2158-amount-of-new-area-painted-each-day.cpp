class Solution {
public:
    map<int,int>ranges;
    int overLapAmount(pair<int,int>segment1, pair<int,int>segment2) {
        if(segment1.first >= segment2.second || segment2.first >= segment1.second) {
            return 0;
        }
        return min(segment1.second,segment2.second) - max(segment1.first,segment2.first);
    }
    
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

    vector<int> amountPainted(vector<vector<int>>& paints) {
        vector<int>result;
        for(vector<int>&paint: paints) {
            int amount = 0, start = paint[0], end = paint[1];
            auto position = getPosition(start, end);
            while(position!=ranges.end() && position->first < paint[1]) {
                amount += overLapAmount({paint[0],paint[1]}, *position);
               
                    start = min(start, position->first);
                    end = max(end, position->second);
                    ranges.erase(position++);
               
            }
            ranges[start] = end;
            result.push_back(paint[1]-paint[0]-amount);
        }
        return result;
    }
};