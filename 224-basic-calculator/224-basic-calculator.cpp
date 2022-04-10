class Solution {
public:
    stack<string>stack;
    string expression;
    
    void removeSpaces() {
        string str = "";
        for(int i = 0; i < expression.size(); ++i) {
            if(expression[i] != ' ') {
                str += expression[i];
            }
        }
        expression = str;
    }
    
    void addOperand(int &i, int sign) {
        string number = sign == 1? "-":"+";
        while(i < expression.size() && isdigit(expression[i])) {
            number += expression[i++];
        }
        stack.push(number);
        i--;
    }
    
    long long getNumber(string s) {
        int value = 1;
        if(s[0] == '-') {
            value = -1;
        }
        long long number = 0;
        for(int i = 1; i < s.size(); ++i) {
            number = number*10+s[i]-'0';
        }
        return number*value;
    }
    
    void compute() {
        long long sum = 0;
        while(stack.size() && stack.top() != "(") {
            sum += getNumber(stack.top()); stack.pop();
        }
        if(stack.size()) {
            stack.pop();
        }
        if(stack.size()) {
            if(stack.top() == "1") {
                sum = -sum;
            }
            stack.pop();
        }
        string result = "+";
        if(sum < 0) {
            result = "-";
        }
        stack.push(result+to_string(abs(sum)));
    }
    
    int calculate(string s) {
        expression = s;
        int sign = 0;
        for(int i = 0; i < expression.size(); ++i) {
            if(isdigit(expression[i])) {
                addOperand(i,sign);
                sign = 0;
            }
            else if(expression[i] == '(') {
                stack.push(to_string(sign));
                stack.push("(");
                sign = 0;
            }
            else if(expression[i] == ')') {
                compute();
            }
            else if(expression[i] == '-'){
                sign = 1;
            }
        }
        compute();
        return stoi(stack.top());
    }
};