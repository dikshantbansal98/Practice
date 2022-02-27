class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>points = {p1,p2,p3,p4};
        vector<int>indexes = {0,1,2,3};
        do {
            set<int>distances;
            for(int i = 0; i < 4; ++i) {
                distances.insert(getDistance(points[indexes[i]],points[indexes[(i+1)%4]]));
            }
            if(distances.size()!=1) {
                continue;
            }
            if(*distances.begin() == 0 || getDistance(points[indexes[0]],points[indexes[2]]) == 0) {
                return false;
            }
            
            if(getDistance(points[indexes[0]],points[indexes[2]]) == getDistance(points[indexes[1]],points[indexes[3]])){
                return true;
            }
        }
        while(next_permutation(indexes.begin(),indexes.end()));
        return false;
    }
    
    int getDistance(vector<int>&p1, vector<int>&p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
};