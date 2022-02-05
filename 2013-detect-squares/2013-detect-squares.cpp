class DetectSquares {
public:
    map<pair<int,int>, int>mp;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        
        int ans = 0;
        for(auto itr : mp)
        {
            pair<int,int>p = itr.first;
            if(p.first != point[0] and p.second != point[1] and (abs(point[0] - p.first) == abs(point[1] - p.second)))
            {
                int first = mp[{p.first, p.second}];
                int second = mp[{p.first, point[1]}];
                int third = mp[{point[0], p.second}];
                
                int cur = first * second * third;
                ans += cur;
            }
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */