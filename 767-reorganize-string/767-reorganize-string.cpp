typedef pair<int,char> customType;
class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26);
        for(char &ch: s) {
            freq[ch-'a']++;
        }
        priority_queue<customType>pq;
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            if(freq[ch-'a']) {
                pq.push({freq[ch-'a'],ch});
            }
        }
        string result = "";
        while(pq.size()) {
            auto [frequency1, character1] = pq.top(); pq.pop();
            if(pq.size() == 0) {
                if(frequency1 > 1) {
                    return "";
                }
                else {
                    result += character1; 
                    return result;
                }
            }
            auto [frequency2, character2] = pq.top(); pq.pop();
            result += character1;
            result += character2;
            if(frequency1 > 1) {
                pq.push({frequency1-1, character1});
            }
            if(frequency2 > 1) {
                pq.push({frequency2-1, character2});
            }
        }
        return result;
    }
};