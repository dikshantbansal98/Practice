class Solution {
public:
    string simplifyPath(string path) {
        stack<string>stack;
        vector<string> components = split(path, '/');
        for(string &str: components) {
            if(str == "." || str == "") {
                continue;
            }
            else if(str == "..") {
                if(stack.size()) {
                    stack.pop();
                }
            }
            else {
                stack.push(str);
            }
        }
        string result;
        while(stack.size()) {
            result = "/" + stack.top() + result;
            stack.pop();
        }
        return result.size() > 0? result:"/";
    }
    
    vector<string> split(string path, char delimiter) {
        string component = "";
        vector<string>components;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == delimiter) {
                components.push_back(component);
                component = "";
            }
            else {
                component += path[i];
            }
        }
        components.push_back(component);
        return components;
    }
};