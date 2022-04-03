class Solution {
public:
    int minimumBuckets(string street) {
        int ans = 0;
        if(street.size()==1){
            return street[0]=='H'?-1:0;
        }
        for(int i = 0; i < street.size(); ++i){
            if(street[i]!='H')continue;
            if(i+1<street.size() && street[i+1]=='.'){
                ans++;
                i = i + 2;
            }
            else{
                if(i && street[i-1]=='.')
                    ans++;
                else
                    return -1;
            }
        }
        return ans;
    }
};