class Solution {
public:
    set<string>validStrings;
    vector<string> removeInvalidParentheses(string s) {
        int removeClosing = 0, extraOpen = 0;
        for(char &ch: s) {
            if(isalpha(ch)) {
                continue;
            }
            extraOpen += ch=='('?1:-1;
            if(extraOpen<0) {
                extraOpen = 0;
                removeClosing++;
            }
        }
        int removeOpening = extraOpen;
        backtrack(s, 0, removeOpening, removeClosing, 0, "");
        vector<string>uniqueValidStrings;
        for(string str: validStrings) {
            uniqueValidStrings.push_back(str);
        }
        return uniqueValidStrings;
    }
    
    void backtrack(string &str, int idx, int removeOpening, int removeClosing, int extraOpen, string result) {
        //base cases
        if(idx >= str.size() && removeOpening == 0 && removeClosing == 0 && extraOpen == 0) {
            validStrings.insert(result);
            return;
        }
        if(idx >= str.size() || removeOpening < 0 || removeClosing < 0 || extraOpen < 0) {
            return;
        }
        
        //logic
        if(isalpha(str[idx])) {
            backtrack(str, idx+1, removeOpening, removeClosing, extraOpen, result+str[idx]);
        }
        else if(str[idx] == '(') {
            backtrack(str, idx+1, removeOpening-1, removeClosing, extraOpen, result);
            backtrack(str, idx+1, removeOpening, removeClosing, extraOpen+1, result+'(');
        }
        else {
            backtrack(str, idx+1, removeOpening, removeClosing-1, extraOpen, result);
            backtrack(str, idx+1, removeOpening, removeClosing, extraOpen-1, result+')');
        }
        
    }
   
};