class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>result(n);
        for(int i = 1; i <= n; ++i) {
            result[i-1] = i;
        }
        sort(result.begin(), result.end(), [](int a, int b){
            return to_string(a)<to_string(b);
        });
        return result;
    }
};