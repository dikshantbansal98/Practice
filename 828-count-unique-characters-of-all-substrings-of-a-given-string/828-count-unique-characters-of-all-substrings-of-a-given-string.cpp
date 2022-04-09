class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int>left = getLastPositionArray(s), right = getNextPositionArray(s);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            ans += (i-left[i])*(right[i]-i);
        }
        return ans;
    }
    
    vector<int> getLastPositionArray(string &s) {
        map<char,int>map;
        vector<int>left(s.size(),-1);
        for(int i = 0; i < s.size(); ++i) {
            if(map.find(s[i])!=map.end()) {
                left[i] = map[s[i]];
            }
            map[s[i]] = i;
        }
        return left;
    }
    
    vector<int> getNextPositionArray(string &s) {
        map<char,int>map;
        vector<int>right(s.size(),s.size());
        for(int i = s.size()-1; i >= 0; --i) {
            if(map.find(s[i])!=map.end()) {
                right[i] = map[s[i]];
            }
            map[s[i]] = i;
        }
        return right;
    }
 };