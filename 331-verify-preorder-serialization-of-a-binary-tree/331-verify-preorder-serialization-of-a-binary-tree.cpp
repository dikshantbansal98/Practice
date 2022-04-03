class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string>result = split(preorder);
        int idx = 0;
        int count = 1;
        if(result.size()==0)
            return true;
        for(string ch:result)
        {
            count--;
            if(count<0)
                return false;
            if(ch!="#")count+=2;
        }
        return count==0;
    }

    vector<string>split(string preorder)
    {
        string val="";
        vector<string>res;
        for(char ch:preorder)
        {
            if(ch==',')
            {
                res.push_back(val);
                val="";
            }
            else
                val+=ch;
        }
        res.push_back(val);
        return res;
    }
};