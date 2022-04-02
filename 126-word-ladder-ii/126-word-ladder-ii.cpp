class Solution {
public:
    vector<vector<string>>ans;
    vector<string>words;
    vector<vector<int>>adj;
    vector<bool>visited;
    vector<int>distances;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        words = wordList;
        if(!isWordPresent(endWord)) {
            return ans;
        }
        if(!isWordPresent(beginWord)) {
            words.push_back(beginWord);
        }
        adj.resize(words.size());
        visited.resize(words.size());
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i+1; j < words.size(); ++j) {
                if(isDistanceOne(words[i],words[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        auto [beginIndex, endIndex] = getIndexes(beginWord,endWord);
        distances = getDistances(beginIndex);
        vector<int>path;
        path.push_back(beginIndex);
        createPaths(beginIndex, path, endIndex);
        return ans;
    }
    
    void createPaths(int start, vector<int>&path, int end, int distance = 0) {
        if(start == end) {
            addPath(path);
        }
        for(int &to: adj[start]) {
            if(!visited[to] && distances[to] == distance+1) {
                path.push_back(to);
                visited[to] = true;
                createPaths(to, path, end, distance+1);
                path.pop_back();
                visited[to] = false;
            }
        }
    }
    
    void addPath(vector<int>path) {
        vector<string>stringPath;
        for(int &i: path) {
            stringPath.push_back(words[i]);
        }
        ans.push_back(stringPath);
    }
    
    vector<int> getDistances(int beginIndex) {
        vector<int>distanceArray(words.size(),1e9);
        distanceArray[beginIndex] = 0;
        queue<int>q;
        q.push(beginIndex);
        while(!q.empty()) {
            int start = q.front(); q.pop();
            for(int &to: adj[start]) {
                if(distanceArray[to]>distanceArray[start]+1) {
                    distanceArray[to] = distanceArray[start]+1;
                    q.push(to);
                }
            }
        }
        return distanceArray;
    }
    
    pair<int,int> getIndexes(string beginWord, string endWord) {
        int beginIndex, endIndex;
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == beginWord) {
                beginIndex = i;
            }
            else if(words[i] == endWord) {
                endIndex = i;
            }
        }
        return {beginIndex, endIndex};
    }
    
    bool isDistanceOne(string word1, string word2) {
        int difference = 0;
        for(int i = 0; i < word1.size(); ++i) {
            if(word1[i] != word2[i]) {
                difference++;
            }
        }
        return difference == 1;
    }
    
    bool isWordPresent(string &searchWord) {
        for(string &word: words) {
            if(word == searchWord) {
                return true;
            }
        }
        return false;
    }
};