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
    int ans = -1e6;
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        helper(root);
        return ans;
    }
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans = max({ans,left+right+root->val});
        return max({root->val+max(left,right),0});
    }
};