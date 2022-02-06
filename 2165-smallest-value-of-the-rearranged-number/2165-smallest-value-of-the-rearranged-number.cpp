class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        bool neg = num < 0;
        num = abs(num);
        long long result = 0;
        vector<int>digits;
        while(num) {
            int digit = num%10;
            num/=10;
            digits.push_back(digit);
        }
        if(neg) {
            sort(digits.rbegin(),digits.rend());
        }
        else{
            sort(digits.begin(),digits.end());
            
            for(int i = 0; i < digits.size(); ++i) {
                if(digits[i]) {
                    int value = digits[i];
                    int j = i;
                    while(j>=1) {
                        digits[j] = digits[j-1];
                        j--;
                    }
                    digits[0] = value;
                    break;
                }
            }
        }
        for(int &digit: digits) {
            result = result*10 + digit;
        }
        if(neg) {
            result = -result;
        }
        return result;
    }
};