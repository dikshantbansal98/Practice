/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *prev=NULL;
	void preorder(TreeNode *root)
	{
		if(!root) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
		if(prev)
		    prev->right = root;
        prev = root;  
        root->left = root->right = NULL;
        
        preorder(left);
		preorder(right);
	}
    void flatten(TreeNode* root) 
    {
        preorder(root);
    }
};