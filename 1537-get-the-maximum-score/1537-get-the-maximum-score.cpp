const int mod = 1e9+7;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long i = 0, j = 0, up = 0, down = 0, ans = 0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]>nums2[j]) {
                down = (down + nums2[j++]);
            }
            else if(nums1[i]<nums2[j]) {
                up = (up+nums1[i++]);
            }
            else {
                ans+= max(up,down)+nums1[i++]%mod;
                j++;
                ans = ans%mod;
                up = down = 0;
            }
           
        }
        while(i<nums1.size())
        {
            up = (up+nums1[i++]);
        }
        while(j<nums2.size())
        {
            down = (down + nums2[j++]);
        }
        return (ans+max(up,down))%mod;
    }
};