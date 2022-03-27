class Solution {
public:
    
    string countOfAtoms(string formula) {
        stack<map<string,int>>st;
        for(int i = 0; i < formula.size(); ++i) {
            if(is_upper(formula[i])) {
                auto [str, j] = firstOperation(i, formula);
                int k = secondOperation(j, formula, i);
                map<string,int>freq;
                freq[str] = k;
                st.push(freq);
            }
            else if(formula[i] == '(') {
                map<string,int>freq;
                st.push(freq);
            }
            else if(formula[i] == ')') {
                int k = secondOperation(i+1, formula, i);
                mergeFrequencies(st, k, true);
            }
            
        }
        mergeFrequencies(st);
        return getFinalOutput(st.top());
    }
    
    void mergeFrequencies(stack<map<string,int>>&st, int k = 1, bool isOpen = false) {
        map<string,int>result;
        while(st.size() && st.top().size()) {
            map<string,int>freq = st.top(); st.pop();
            for(auto [element, frequency]: freq) {
                result[element] += frequency*k;
            }
        }
        if(isOpen) {
            st.pop();
        }
        st.push(result);
    }
    
    bool is_upper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    
    bool is_lower(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    
    bool is_numeric(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    tuple<string,int> firstOperation(int i, string &formula) {
        string str = "";
        str += formula[i];
        int j = i+1;
        while(j<formula.size() && is_lower(formula[j])) {
            str += formula[j++];
        }
        return {str,j};
    }
    
    int secondOperation(int j, string &formula, int &i) {
        int k = 1;
        if(j<formula.size() && is_numeric(formula[j])) {
            k = 0;
            while(j<formula.size() && is_numeric(formula[j])) {
                k = k*10 + (formula[j++]-'0');
            }
        }
        i = j-1;
        return k;
    }
    
    string getFinalOutput(map<string,int>&result) {
        string output = "";
        for(auto [element, frequency]: result) {
            output+=element;
            if(frequency > 1) {
                output += to_string(frequency);
            }
        }
        return output;
    }
};