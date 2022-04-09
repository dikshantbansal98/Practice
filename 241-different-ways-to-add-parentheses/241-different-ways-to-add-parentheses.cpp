class Solution {
public:
    vector<int>nums;
    string operators;
    int calculate(int num1, int num2, char op){
        if(op == '+'){
            return num1+num2;
        }
        else if(op == '-'){
            return num1-num2;
        }
        else if(op == '*'){
            return num1*num2;
        }
        return   num1/num2;
    }
    vector<int> diffWaysToCompute(string expression) {
        int num = 0;
        for(char &ch:expression){
            if(ch>='0'&&ch<='9'){
                num = num*10+ch-'0';
            }
            else{
                nums.push_back(num);
                operators+=ch;
                num = 0;
            }
        }
        nums.push_back(num);
        int n = nums.size();
        vector<int> dp[n][n];
        for(int l = 1; l <= n; ++l ){
            for(int i = 0; i < n-l+1; ++i){
                int j = i+l-1;
                if(l==1)
                {
                    dp[i][j] = vector<int>(1,nums[i]);
                }
                else if(l==2){
                    dp[i][j] = vector<int>(1,calculate(nums[i],nums[j],operators[i]));
                }
                else{
                    vector<int>result;
                    for(int k = i; k < j; ++k){
                        auto vleft = dp[i][k];
                        auto vright = dp[k+1][j];
                        
                        for(int x = 0; x < vleft.size(); ++x){
                            for(int y = 0; y < vright.size(); ++y){
                                result.push_back(calculate(vleft[x],vright[y],operators[k]));
                            }
                        }
                    }
                    dp[i][j] = result;
                    
                }
            }
        }
        return dp[0][n-1];
    }
};