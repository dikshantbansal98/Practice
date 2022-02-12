const int mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long totalSum = 0;
        stack<int>st, st2;
        vector<long long>leftMinIndex(arr.size(),-1), rightMinIndex(arr.size(),arr.size());
        st.push(0);
        for(int i = 1; i < arr.size(); ++i) {
            while(st.size() && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            if(st.size()) {
                leftMinIndex[i] = st.top();
            }
            else{
                leftMinIndex[i] = -1;
            }
            st.push(i);
        }
        
        st2.push(arr.size()-1);
        for(int i = arr.size()-2; i >= 0; --i) {
            while(st2.size() && arr[st2.top()]>arr[i]) {
                st2.pop();
            }
            if(st2.size()) {
                rightMinIndex[i] = st2.top();
            }
            else{
                rightMinIndex[i] = arr.size();
            }
            st2.push(i);
        }
        for(int i = 0; i < arr.size(); ++i) {
            totalSum += arr[i]*(i-leftMinIndex[i])*(rightMinIndex[i]-i);
            totalSum %= mod;
        }
        return totalSum;
    }
};