class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int n = A.size();
  vector<int>oddInd;
  oddInd.push_back(-1);
  for(int i=0; i<n; i++){
    if(A[i]%2){
      oddInd.push_back(i);
    }
  }
  oddInd.push_back(n);
  int m = oddInd.size();
  if(m-2 < k){
    return 0;
  }
  int ans = 0;
  int j = 1;
  for(int i=k+1; i<m; i++){
    ans += (oddInd[i] - oddInd[i-1])*(oddInd[j] - oddInd[j-1]);
    j++;
  }
  return ans;
    }
};