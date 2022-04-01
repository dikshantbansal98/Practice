class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return findMinDistance(wordList,beginWord,endWord);
    }
    int findMinDistance(vector<string>&words , string begin, string end)
    {
        queue<string>q;
        int step = 1;
        q.push(begin);
        vector<bool>seen(words.size());
        unordered_map<string,vector<int>>graph;
        for(int i = 0; i < words.size(); ++i)
        {
            string str = words[i];
            for(int j = 0; j < words[i].size(); ++j)
            {
                str[j] = '*';
                graph[str].push_back(i);
                str[j] = words[i][j];
            }
        }
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string str = q.front(); q.pop();
                if(str == end)
                    return step;
                for(int i = 0; i < str.size(); ++i)
                {
                    char ch = str[i];
                    str[i] = '*';
                    for(auto it:graph[str])
                    {
                        if(!seen[it])
                        {
                            q.push(words[it]);
                            seen[it] = true;
                        }
                    }
                    str[i] = ch;
                }
            }
            step++;
        }
        return 0;
    }

};