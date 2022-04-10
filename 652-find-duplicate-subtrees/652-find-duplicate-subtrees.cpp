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
    unordered_set<string>hash, values;
    vector<TreeNode*>ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ans;
    }
    string helper(TreeNode* root)
    {
        if(root==NULL)
            return "X";
        string left = helper(root->left);
        string right = helper(root->right);
        string result = left + 'L'+ to_string(root->val)+right+'R';
        if(hash.find(result)!=hash.end() && values.find(result)==values.end())
            ans.push_back(root),values.insert(result);
        hash.insert(result);
        return result;
    }
};