class Solution {
public:
    vector<vector<int>>adj;
    vector<int>visited;
    bool canConvert(string str1, string str2) {
        unordered_set<char>uniques;
        unordered_map<char,char>hash;
        if(str1 == str2) {
            return true;
        }
        for(int i = 0; i < str1.size(); ++i) {
            uniques.insert(str2[i]);
            if(hash.find(str1[i]) != hash.end() && hash[str1[i]]!=str2[i]) {
                return false;
            }
            hash[str1[i]] = str2[i];
        }
        return uniques.size()<26;
    }

};