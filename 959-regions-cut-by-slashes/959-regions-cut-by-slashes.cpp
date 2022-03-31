#include <bits/stdc++.h>
using namespace std;

class dsu 
{
public:
  vector<int> p,size;
  int n;
  dsu(int _n) : n(_n) 
  {
    p.resize(n+1);
    size.resize(n+1,1);
    for(int i = 0; i <= n; ++i)
      p[i] = i;
  }

  int parent(int x) 
  {
    return p[x] = (x == p[x]) ? x : parent(p[x]);
  }
  bool merge(int x, int y)
  {
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
    return true;
  }
};
class Solution 
{
public:
	int rows, cols;
    int regionsBySlashes(vector<string>& grid) 
    {
        rows = grid.size();
        cols = grid[0].size();
        dsu d(4*rows*cols);
        for(int i = 0; i < rows; ++i) {
        	for(int j = 0; j < cols; ++j) {
        		int root = 4*(i*cols+j);
        		char ch = grid[i][j];
        		if(ch != '\\') {
        			d.merge(root+0,root+1);
        			d.merge(root+2,root+3);
        		}
        		if(ch != '/') {
        			d.merge(root+0,root+2);
        			d.merge(root+1,root+3);
        		}
        		if(i) {
        			d.merge(root+0,root-4*cols+3);
        		}
        		if(j) {
        			d.merge(root+1,root-4+2);
        		}
        	}
        }
        set<int>components;
        for(int i = 0; i<4*rows*cols; ++i)
        	components.insert(d.parent(i));
        return components.size();

    }
};