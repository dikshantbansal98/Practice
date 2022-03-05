class Solution {
public:
    bool compare(vector<int>&a,vector<int>&b)
    {
        return a==b;
    }
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>a(26),b(26),ans;
        for(auto it:p)
        {
            b[it-'a']++;
        }
        for(int i = 0;i<s.size();++i)
        {
            a[s[i]-'a']++;
            if(i>=p.size())
                a[s[i-p.size()]-'a']--;
            if(compare(a,b))
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};