const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class dsu {
public:
  vector<int> p,size;
  int n,maxSize;
  dsu(int _n) : n(_n) {
    p.resize(n);
    maxSize = 0;
    size.resize(n,1);
    for(int i = 0; i < n; ++i)
      p[i] = i;
  }

  int parent(int x) {
    return p[x] = (x == p[x]) ? x : parent(p[x]);
  }
    
  bool merge(int x, int y) {
    int px=parent(x);
    int py=parent(y);
    if(px==py)
      return false;
    if(size[px]>=size[py])
    {
        size[px]+=size[py];
        p[py]=p[px];
    }
    else
    {
        size[py]+=size[px];
        p[px]=p[py];
    }
    maxSize = max(size[py],size[px]);
    return true;
  }

};
class Solution {
public:
    int rows, cols;
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        cols = grid[0].size();
        dsu d(rows*cols);
        for(int x = 0; x < grid.size(); ++x) {
            for(int y = 0; y < grid[x].size(); ++y) {
                if(grid[x][y] == 1) {
                    d.maxSize = max(d.maxSize,1);
                    for(int k = 0; k < 4; ++k) {
                        int nx = x+dx[k], ny = y+dy[k];
                        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[x].size() && grid[nx][ny]==1) {
                            d.merge(x*cols+y, nx*cols+ny);
                        }
                    }
                }
            }
        }
        for(int x = 0; x < grid.size(); ++x) {
            for(int y = 0; y < grid[x].size(); ++y) {
                if(grid[x][y] == 0) {
                    set<int>parents;
                    for(int k = 0; k < 4; ++k) {
                        int nx = x+dx[k], ny = y+dy[k];
                        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[x].size() && grid[nx][ny]==1) {
                            parents.insert(d.parent(nx*cols+ny));
                        }
                    }
                    int value = 1;
                    for(int parent: parents) {
                        value += d.size[parent];
                    }
                    d.maxSize = max(d.maxSize,value);
                }
                
            }
        }
        return d.maxSize;
        
    }
};