class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<>();
    map.put(0,1);
    int oddCount = 0;
    int ans = 0;
    int n = nums.length;
    for(int i = 0;i<n;i++){
      if(nums[i]%2 == 1){
        oddCount++;
      }
      map.put(oddCount,map.getOrDefault(oddCount,0)+1);
      ans = ans + map.getOrDefault(oddCount-k, 0);
        
    }
        return ans;  
    }
}