class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n=A.size();
        vector<bool>dp1(n),dp2(n);
        dp1[n-1]=dp2[n-1]=true;
        map<int,int>m1,m2;
        m1[A[n-1]]=n-1;
        m2[-A[n-1]]=n-1;
        for(int i=n-2;i>=0;--i)
        {
           int idx=m1.lower_bound(A[i])->second;
           dp1[i]=(dp1[i]||dp2[idx]);
           m1[A[i]]=i;
           idx=m2.lower_bound(-A[i])->second;
           dp2[i]=(dp2[i]||dp1[idx]);
           m2[-A[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;++i)
            ans+=dp1[i];
        return ans;
    }
};