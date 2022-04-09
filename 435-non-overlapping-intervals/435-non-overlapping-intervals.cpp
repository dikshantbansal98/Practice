class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int> &a, vector<int> &b)
             {
                 if(a[1]!=b[1])
                     return a[1]<b[1];
                 return a[0]<b[0];
             });
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
            if(res.back()[1]<=intervals[i][0])
                res.push_back(intervals[i]);
            
        return intervals.size()-res.size();
    }
};