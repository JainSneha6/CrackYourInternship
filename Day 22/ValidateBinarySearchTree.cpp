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
    bool isValid(TreeNode* root, long long low, long long high){
        if(root==NULL){
            return true;
        }
        if(root->val<=low || root->val>=high){
            return false;
        }
        return isValid(root->left,low,root->val) && isValid(root->right,root->val,high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};
