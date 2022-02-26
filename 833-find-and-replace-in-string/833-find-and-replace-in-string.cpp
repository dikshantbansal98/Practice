class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector< tuple<int, string, string> >input;
        for(int i = 0; i < indices.size(); ++i) {
            input.push_back({indices[i], sources[i], targets[i]});
        }
        sort(input.begin(), input.end());
        string result = "";
        int last = -1;
        for(int i = 0; i < indices.size(); ++i) {
            auto &[index, source, target] = input[i];
            for(int j = last+1; j < index; ++j) {
                result += s[j];
            }
            last = index-1;
            if(s.substr(index, source.size()) == source) {
                result += target;
                last = index+source.size()-1;
            }
            
        }
        for(int j = last+1; j < s.size(); ++j) {
            result += s[j];
        }
        return result;
    }
};