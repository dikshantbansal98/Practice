class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        makeEnvelopesSorted(envelopes);
        vector<int>heights;
        for(auto &envelope: envelopes) {
            heights.push_back(envelope[1]);
        }
        vector<int>order(heights.size()+1, 1e9);
        for(auto height: heights) {
            int index = lower_bound(order.begin(), order.end(), height)-order.begin();
            order[index] = height;
        }
        for(int i = 0; i < order.size(); ++i) {
            if(order[i] == 1e9) {
                return i;
            }
        }
        return 1;
    }
    
    void makeEnvelopesSorted(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b) {
            if(a[0]!=b[0]) {
                return a[0]<b[0];
            }
            return a[1]>b[1];
        });
    }
};
 
        
    