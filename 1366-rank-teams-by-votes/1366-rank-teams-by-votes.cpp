class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>>data(26, vector<int>(votes[0].size()));
        for(auto &vote: votes) {
            for(int i = 0; i < vote.size(); ++i) {
                data[vote[i]-'A'][i]++;
            }
        }
        map<int,vector<pair<int,int>>>orderedSet;
        for(int i = 0; i < data.size(); ++i) {
            for(int j = 0; j < data[i].size(); ++j) {
                if(data[i][j] > 0) {
                    orderedSet[i].push_back({j,-data[i][j]});
                }
            }
        }
        set<pair<vector<pair<int,int>>,char>>orderedResultantSet;
        for(auto &[characterIndex, freqIndexArray]: orderedSet) {
            orderedResultantSet.insert({freqIndexArray, characterIndex});
        }
        string ans = "";
        for(auto [set,characterIndex]: orderedResultantSet) {
            ans += 'A'+characterIndex;
        }
        return ans;
    }
};
