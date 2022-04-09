class Solution {
    int rows, cols;
    int ans = -1e8;
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int &p) {
        rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < cols; ++i)
        {
            vector<int>array(rows);
            for(int j = i; j < cols; ++j)
            {
                for(int  k = 0; k < rows; ++k)
                    array[k]+=matrix[k][j];
                calculate(array,p);
            }
        }
        return ans;
    }
    void calculate(vector<int>&array,int &k)
    {
        int sum = 0;
        set<int>st;
        st.insert(0);
        for(int i = 0; i < array.size(); ++i)
        {
            sum += array[i];
            auto it = st.lower_bound(sum-k);
            if(it!=st.end())
            {
                int val = *it;
                ans = max(ans,sum-val);
            }
            st.insert(sum);
        }
    }
};