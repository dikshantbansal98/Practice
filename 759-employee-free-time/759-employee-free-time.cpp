/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int size = schedule.size();
        while(size > 1) {
            for(int i = 0; i < size/2; ++i) {
                schedule[i] = merge(schedule[i],schedule[size-i-1]);
            }
            size = size-size/2;
        }
        vector<Interval> result;
        Interval last = schedule[0][0];
        for(int i = 1; i < schedule[0].size(); ++i) {
           if(last.end < schedule[0][i].start) {
               result.push_back(Interval(last.end, schedule[0][i].start));
           }
           last = schedule[0][i];
        }
        return result;
    }
    
    vector<Interval> merge(vector<Interval>first, vector<Interval>second) {
        int i = 0;
        vector<Interval>result;
        for(auto interval: second) {
            first.push_back(interval);
        }
        sort(first.begin(),first.end(), [](Interval a, Interval b) {
            if(a.start == b.start) {
                return a.end<b.end;
            }
            return a.start < b.start;
        });
        while(i < first.size()) {
            Interval merger = first[i];
            if(result.size() == 0 || result.back().end < merger.start) {
                result.push_back(merger);
            }
            else {
                result[result.size()-1] = Interval(min(result.back().start,merger.start), max(merger.end,result.back().end));
            }
            i++;
        }
        return result;
    }
};