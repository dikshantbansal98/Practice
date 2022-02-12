class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>stN;
        string result = "";
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                int num = 0, j = i;
                for(; j < s.size() && isdigit(s[j]); ++j) {
                    num = num*10 + s[j]-'0';
                }
                i = j-1;
                stN.push(num);
            }
            else if(s[i] == '[') {
                st.push(result);
                result = "";
            }
            else if(s[i] == ']') {
                int num = stN.top();
                stN.pop();
                string temp = result;
                while(num>1) {
                    result += temp;
                    num--;
                }
                result = st.top() + result;
                st.pop();
            }
            else{
                result += s[i];
            }
        }
        return result;
    }
};