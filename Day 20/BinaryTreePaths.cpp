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
private:
    void path(TreeNode* root, string s, vector<string>& ans){
        if(root==NULL){
            return;
        }
        string val = to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s+=val;
            ans.push_back(s);
            return;
        }
        path(root->left,s+val+"->",ans);
        path(root->right,s+val+"->",ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root,"",ans);
        return ans;
    }
};
