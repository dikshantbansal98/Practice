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
        int i;
        for(i = 0;i<min(p.size(),s.size());++i)
        {
            a[s[i]-'a']++;
        }
        if(compare(a,b))
            ans.push_back(0);
        for(;i<s.size();++i)
        {
            a[s[i]-'a']++;
            a[s[i-p.size()]-'a']--;
            if(compare(a,b))
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};