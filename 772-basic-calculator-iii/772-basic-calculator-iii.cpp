class Solution {
public:
    int precedence(char ch)
    {
        if(ch == '+' || ch == '-')
        return 1;
        if(ch == '*' || ch == '/')
        return 2;
        
        return 0;
        
    }
    int operation(int first,int second, char op)
    {
        if(op == '+')
            return first + second;
        else if(op == '-')
            return first - second;
        else if(op == '*')
            return first*second;
        return first/second;
    }
    int calculate(string &s) {
        // Write your code here
        string str = "";
        stack<char>operators;
        stack<int>operand;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] != ' ')
                str += s[i];
        for(int i = 0; i < str.size(); ++i)
        {
            char ch = str[i];
            if(isdigit(ch))
            {
                int val = 0;
                while(i<str.size() && isdigit(str[i]))
                {
                    val = val*10 + str[i]-'0';i++;
                }
                i--;
                operand.push(val);
            }
            else if(ch == '(')
                operators.push(ch);
            else if(ch == ')')
            {
                while(operators.top()!='(')
                {
                    int second = operand.top(); operand.pop();
                    int first = operand.top(); operand.pop();
                    operand.push(operation(first,second,operators.top()));
                    operators.pop();
                }
                operators.pop();
            }
            else
            {
                while(operators.size() && precedence(operators.top())>=precedence(ch))
                {
                    int second = operand.top(); operand.pop();
                    int first = operand.top(); operand.pop();
                    operand.push(operation(first,second,operators.top()));
                    operators.pop();
                }
                operators.push(ch);
            }

        }
        while(operators.size())
        {
            int second = operand.top(); operand.pop();
            int first = operand.top(); operand.pop();
            operand.push(operation(first,second,operators.top()));
            operators.pop();
        }
        return operand.top();
    }
};
