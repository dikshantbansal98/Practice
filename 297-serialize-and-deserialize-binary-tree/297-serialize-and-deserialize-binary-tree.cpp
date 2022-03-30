/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    int inf;
    void serialHelper(TreeNode* root, string &serial)
    {
        if(!root)
        {
            serial+=to_string(1e4)+'#';
            return;
        }
        serial+=to_string(root->val)+"#";
        serialHelper(root->left,serial);
        serialHelper(root->right,serial);
    }
    string serialize(TreeNode* root) {
        inf = 1e4;
        string res = "";
        serialHelper(root,res);
        return res;
    }
    vector<string>split(string data)
    {
        vector<string>res;
        string str = "";
        for(char ch:data)
        {
            if(ch=='#')
            {
                res.push_back(str);
                str="";
                continue;
            }
            str+=ch;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        vector<string> result = split(data);
        int x = 0;
        return deserialHelper(result,x);
    }
    TreeNode* deserialHelper(vector<string>&deserial, int &x) {
        if(x>=(int)deserial.size())
            return NULL;
        int value = stoi(deserial[x]);
        if(value == 1e4) {
            return NULL;
        }
        TreeNode *node = new TreeNode(stoi(deserial[x]));
        node->left = deserialHelper(deserial,++x);
        node->right = deserialHelper(deserial,++x);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));