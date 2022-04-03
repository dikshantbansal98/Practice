class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>result;
        map<int,int>frequencies;
        for(int &num: nums) {
            frequencies[num]++;
        }
        for(auto &[element,frequency]: frequencies) {
            result.push_back({frequency,element});
        }
        sort(result.rbegin(),result.rend());
        vector<int>topK;
        for(auto &[frequency, element]: result) {
            if(k==0) {
                break;
            }
            k--;
            topK.push_back(element);
        }
        return topK;
    }
};