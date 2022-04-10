class Solution {
public:
    stack<char>operators;
    stack<long long>operand;
    int precedence(char ch) {
        if(ch == '+' || ch == '-')
            return 1;
        if(ch == '*' || ch == '/' || ch == '%')
            return 2;
        return 0;
    }
    
    long long operation(long long first, long long second, char op) {
        if(op == '+')
            return first + second;
        else if(op == '-')
            return first - second;
        else if(op == '*')
            return first*second;
        return first/second;
    }
    
    void removeEmptyChars(string &s) {
        string str = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ' ') {
                str += s[i];
            }
        }
        s = str;
    }
    
    void computeLastValues() {
        while(operators.size() && operators.top()!='(') {
            compute();
        }
        if(operators.size()) {
            operators.pop();
        }
    }
    
    void addOperand(string &s, int &i) {
        long long val = 0;
        while(i<s.size() && isdigit(s[i])) {
            val = val*10 + s[i]-'0';
            i++;
        }
        i--;
        operand.push(val);
    }
    
    void compute() {
        long long second = operand.top(); operand.pop();
        long long first = operand.top(); operand.pop();
        operand.push(operation(first,second,operators.top()));
        operators.pop();
    }
    
    int calculate(string &s) {
        removeEmptyChars(s);
        for(int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if(isdigit(ch)) {
                addOperand(s,i);
            }
            else {
                while(operators.size() && precedence(operators.top())>=precedence(ch)) {
                    compute();
                }
                operators.push(ch);
            }

        }
        computeLastValues();
        return operand.top();
    }
};
