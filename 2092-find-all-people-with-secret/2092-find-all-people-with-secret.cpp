class DSU {
    public:
    vector<int>root, rank;
    int n;
    DSU(int _n, int firstPerson) {
        n = _n;
        root = vector<int>(n);
        rank = vector<int>(n,1);
        for(int i = 0; i < n; ++i) {
            root[i] = i;
        }
        root[firstPerson] = 0;
        rank[0] = 1e9;
    }

    void reset(int x) {
        root[x] = x;
    }
    
    int getRoot(int x) {
        return root[x] = x == root[x]?x:getRoot(root[x]);
    }
    
    bool merge(int x, int y) {
        int rootX = getRoot(x), rootY = getRoot(y);
        if(rootX == rootY) {
            return false;
        }
        if(rank[rootX]>rank[rootY]) {
            rank[rootX] += rank[rootY];
            root[rootY] = rootX;
        }
        else {
            rank[rootY] += rank[rootX];
            root[rootX] = rootY;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map< int, vector< vector<int> > >meetingsTiming;
        for(auto &meeting : meetings) {
            meetingsTiming[meeting[2]].push_back({meeting[0], meeting[1]});
        }
        vector<int> result;
        DSU dsu(n, firstPerson);
        for(auto &[time, edges]: meetingsTiming) {
            for(auto &edge: edges) {
                dsu.merge(edge[0], edge[1]);
            }
            for(auto edge: edges) {
                if(dsu.getRoot(edge[0]) != 0) {
                    dsu.reset(edge[0]);
                }
                if(dsu.getRoot(edge[1]) != 0) {
                    dsu.reset(edge[1]);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(dsu.getRoot(i) == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};