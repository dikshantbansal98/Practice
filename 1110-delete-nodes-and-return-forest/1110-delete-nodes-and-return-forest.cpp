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
    vector<TreeNode*> roots;
    unordered_set<int>toBeDeleted;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int &val: to_delete) {
            toBeDeleted.insert(val);
        }
        root = deleteNodes(root);
        if(root) {
            roots.push_back(root);
        }
        return roots;
    }
    
    TreeNode* deleteNodes(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        root->left = deleteNodes(root->left);
        root->right = deleteNodes(root->right);
        if(toBeDeleted.find(root->val)!=toBeDeleted.end()) {
            if(root->left) {
                roots.push_back(root->left);
            }
            if(root->right) {
                roots.push_back(root->right);
            }
            delete root;
            return NULL;
        }
        return root;
    }
};