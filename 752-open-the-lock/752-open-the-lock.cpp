const int dx[] = {-1,1};
class Solution {
    set<string>dead;
public:
    int openLock(vector<string>& deadends, string target) {
        for(auto deadend:deadends) {
            dead.insert(deadend);
            if(deadend == "0000" || deadend == target) {
                return -1;
            }
        }
        queue<pair<string,int>>q;
        q.push({"0000",0});
        while(!q.empty()) {
            auto [str,distance] = q.front(); q.pop();
            if(str == target) {
                return distance;
            }
            for(int i = 0; i < 4; ++i) {
                int val = str[i]-'0';
                for(int j = 0; j < 2; ++j) {
                    int newVal = (val + dx[j] + 10)%10;
                    string newString = str;
                    newString[i] = '0'+newVal;
                    if(dead.find(newString) == dead.end()) {
                        q.push({newString, distance+1});
                        dead.insert(newString);
                    }
                }
            }
        }
        return -1;
    }
};