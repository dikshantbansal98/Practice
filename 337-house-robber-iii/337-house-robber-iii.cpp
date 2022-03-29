/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> solve(TreeNode* root, int &ans)
    {
    	if(!root) {
            return {0,0};
        }
    	auto [leftInclude, leftExclude] = solve(root->left, ans);
        auto [rightInclude, rightExclude] = solve(root->right, ans);
        int include = root->val+leftExclude+rightExclude;
        int exclude = max(leftInclude, leftExclude)+max(rightInclude, rightExclude);
        ans = max({ans,include,exclude});
        return {include,exclude};
    }

    int rob(TreeNode* root) 
    {
        if(!root)
        	return 0;
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};