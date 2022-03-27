class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string,int>>st;
        for(int i = 0; i < formula.size(); ++i) {
            if(is_upper(formula[i])) {
                string str = "";
                str += formula[i];
                int j = i+1;
                while(j<formula.size() && is_lower(formula[j])) {
                    str += formula[j++];
                }
                int k = 1;
                if(j<formula.size() && is_numeric(formula[j])) {
                    k = 0;
                    while(j<formula.size() && is_numeric(formula[j])) {
                        k = k*10 + (formula[j++]-'0');
                    }
                }
                i = j-1;
            
                map<string,int>freq;
                freq[str] = k;
                st.push(freq);
            }
            else if(formula[i] == '(') {
                map<string,int>freq;
                st.push(freq);
            }
            else if(formula[i] == ')') {
                int j = i+1;
                int k = 1;
                if(j<formula.size() && is_numeric(formula[j])) {
                    k = 0;
                    while(j<formula.size() && is_numeric(formula[j])) {
                        k = k*10 + (formula[j++]-'0');
                    }
                }
                i = j-1;
                map<string,int>result;
                while(st.size() && st.top().size()) {
                    map<string,int>freq = st.top(); st.pop();
                    for(auto [element, frequency]: freq) {
                    
                        result[element] += frequency*k;
                    }
                }
                
                st.pop();
                st.push(result);
            }
            
        }
        map<string,int>result;
        while(st.size()) {
            map<string,int>freq = st.top(); st.pop();
            for(auto [element, frequency]: freq) {
                result[element] += frequency;
            }
        }
        string output = "";
        for(auto [element, frequency]: result) {
            output+=element;
            if(frequency > 1) {
                output += to_string(frequency);
            }
        }
        return output;
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
};