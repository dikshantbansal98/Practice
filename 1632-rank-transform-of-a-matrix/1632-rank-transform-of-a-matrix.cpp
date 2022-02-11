class Dsu {
    public:
    int n;
    vector<int>root, size;
    Dsu(int _n): n(_n+1) {
        root = vector<int>(n+1);
        size = vector<int>(n+1,1);
        for(int i = 0; i <= n; ++i) {
            root[i] = i;
        }
    }
    int getRoot(int x) {
        return root[x] = root[x] == x? x:getRoot(root[x]);
    }
    bool merge(int x, int y) {
        int rootX = getRoot(x);
        int rootY = getRoot(y);
        if(rootX == rootY)
            return false;
        if(size[rootX]>size[rootY]) {
            size[rootX] += size[rootY];
            root[rootY] = root[rootX];
        }
        else {
           size[rootY] += size[rootX];
           root[rootX] = root[rootY]; 
        }
        return true;
    }
};

class Solution {
public:
    vector<int>rows, cols;
    vector<vector<int>>result;
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        rows = vector<int>(matrix.size());
        cols = vector<int>(matrix[0].size());
        result = vector<vector<int>>(rows.size(),vector<int>(cols.size()));
        map<int,vector<pair<int,int>>>map;
        for(int i = 0; i < rows.size(); ++i) {
            for(int j = 0; j < cols.size(); ++j) {
                map[matrix[i][j]].push_back({i,j});
            }
        }
        for(auto [value, coordinates]: map) {
            Dsu d(rows.size()+cols.size());
            for(auto [x,y]: coordinates) {
                d.merge(x,y+rows.size());
            }
            vector<int>midResult(rows.size()+cols.size());
            for(auto [x,y]: coordinates) {
                midResult[d.getRoot(x)] = max(max(rows[x],cols[y])+1,midResult[d.getRoot(x)]);
            }
            for(auto [x,y]: coordinates) {
                result[x][y] = rows[x] = cols[y] = midResult[d.getRoot(x)];
            }
        }
        return result;
    }
};