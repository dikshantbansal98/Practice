class DetectSquares {
public:
    vector<vector<int>> frequencies;
    vector<pair<int,int>>points;
    DetectSquares() {
        frequencies = vector<vector<int>>(1001, vector<int>(1001));
    }
    
    void add(vector<int> point) {
        frequencies[point[0]][point[1]]++;
        if(frequencies[point[0]][point[1]] == 1)
            points.push_back({point[0],point[1]});
    }
    
    int count(vector<int> point) {
        int count = 0;
        for(auto [x,y]: points) {
            if(x != point[0] and y != point[1] and (abs(point[0] - x) == abs(point[1] - y))) {
                count += (frequencies[point[0]][y]) * (frequencies[x][point[1]]) * (frequencies[x][y]);
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */