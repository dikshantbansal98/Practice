const int inf = 1e4;
class dsu{
	public:
		vector<int>root, size;
		int count;
	dsu()
	{
		root = vector<int>(2*1e4);
		size = vector<int>(2*1e4,1);
		for(int i = 0; i < root.size(); ++i)
            root[i] = i;
	}
	int findRoot(int x)
	{
		return root[x] = root[x] == x? x:findRoot(root[x]);
	}
	bool merge(int x, int y)
	{
		int rootX = findRoot(x), rootY = findRoot(y);
		if(rootX == rootY)	return false;
		if(size[rootX]>size[rootY])
		{
			size[rootX]+= size[rootY];
			root[rootY] = rootX;
		}
		else
		{
			size[rootY]+= size[rootX];
			root[rootX] = rootY;
        }
        count--;
        return true;
	}
		
};
class Solution {
int rows;
public:
    int removeStones(vector<vector<int>>& stones) {
	rows = stones.size();
	dsu d;
    set<int>s1,s2;
     for(int i = 0; i < rows; ++i)
	    s1.insert(stones[i][0]), s2.insert(stones[i][1]);
    d.count = s1.size() + s2.size();
    for(int i = 0; i < rows; ++i)
	    d.merge(stones[i][0],stones[i][1]+inf);
	return rows - d.count;
    }
};
