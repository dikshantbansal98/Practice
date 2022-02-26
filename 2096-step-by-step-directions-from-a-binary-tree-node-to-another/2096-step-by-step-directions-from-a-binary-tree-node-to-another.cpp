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
    string belowPath;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = getLca(root, startValue, destValue);
        int value = getDistance(lca, startValue);
        string result = "";
        while(value--) {
            result += 'U';
        }
        belowPath = "";
        string path = "";
        getPath(lca, path, destValue);
        return result+belowPath;
    }
    
    void getPath(TreeNode *root, string &path, int value) {
        if(root == NULL) {
            return;
        }
        if(root->val == value) {
            belowPath = path;
            return;
        }
        path += 'L';
        getPath(root->left, path, value);
        path.pop_back();
        path += 'R';
        getPath(root->right, path, value);
        path.pop_back();
    }
    
    
    int getDistance(TreeNode *root, int value) {
        if(root == NULL) {
            return 1e9;
        }
        if(root->val == value) {
            return 0;
        }
        return min(getDistance(root->left, value), getDistance(root->right, value))+1;
    }
        
    TreeNode* getLca(TreeNode* root, int value1, int value2) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == value1 || root->val == value2) {
            return root;
        }
        auto left = getLca(root->left, value1, value2);
        auto right = getLca(root->right, value1, value2);
        if(left && right) {
            return root;
        }
        if(left) {
            return left;
        }
        return right;
    }
};
