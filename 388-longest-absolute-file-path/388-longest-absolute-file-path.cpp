class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string>files;
        string str = "";
        for(int i = 0; i <= input.size(); ++i) {
            if(i == input.size()||input[i]=='\n')
                files.push_back(str),str="";
            else
                str += input[i];
        }
        int ans = 0;
        map<int,int>depth;
        for(string &str:files) {
            int i;
            for(i = 0; i < str.size() && str[i]=='\t'; ++i);
            depth[i] = depth[i-1]+(int)str.size()-i;
            if(str.find('.') < str.size()) {
                ans = max(ans,depth[i]+i); // i represents number of forward slashes here
            }
        }
        return ans;
    }
};

/*
dir
\tsubdir1
\tsubdir2
\t\tfile.ext

0 -> 3 
1 -> 10
2 -> 18
*/
