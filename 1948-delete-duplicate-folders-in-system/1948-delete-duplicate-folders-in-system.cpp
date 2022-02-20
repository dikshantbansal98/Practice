struct Node {
    unordered_map<string,Node*>children;
    int index;
    string str;
    Node() {
        index = -1;
        str = "";
    }
};

class Solution {
public:
    Node *Root;
    unordered_map<string, vector<int>> duplicateIndexesMap;
    vector<vector<string>> result;
    unordered_set<int>indexes;
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Root = new Node();
        sort(paths.begin(), paths.end());
        for(int i = 0; i < paths.size(); ++i) {
            insert(paths[i], i);
        }
        dfs(Root);
        for(auto &[key, duplicateIndexes]: duplicateIndexesMap){
            if(duplicateIndexes.size()>1) {
                for(int &index: duplicateIndexes) {
                    indexes.insert(index);
                }
            }
        }
        fillAllPaths(Root, vector<string>());
        return result;
    }
    
    void fillAllPaths(Node *root, vector<string>path) {
        if(indexes.find(root->index)!=indexes.end()) {
            return;
        }
        if(root->str.size()>0) {
            path.push_back(root->str);
            result.push_back(path);
        }
        for(auto [key, childNode]: root->children) {
            fillAllPaths(childNode, path);
        }
    }
    
    string dfs(Node *root) {
        string serializedString = "";
        for(auto [key, childNode]: root->children) {
            string childSerializedString = dfs(childNode);
            serializedString += "#" + childSerializedString + "#";
        }
        if(serializedString.size() > 0) {
            duplicateIndexesMap[serializedString].push_back(root->index);
        }
        return "#" + root->str + serializedString+"#";
    }
    
    
    void insert(vector<string>&path, int index) {
        Node *root = Root;
        for(int i = 0; i < path.size(); ++i) {
            if(root->children.find(path[i]) == root->children.end()) {
                root->children[path[i]] = new Node();
                root->children[path[i]]->str = path[i];
            }
            root = root->children[path[i]];
        }
        root->index = index;
    }
};