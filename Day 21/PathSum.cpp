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
    bool Path(TreeNode* root, int ans, int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            ans+=root->val;
            if(ans==targetSum){
                return true;
            }
        }
        return Path(root->left,ans+root->val,targetSum)||Path(root->right,ans+root->val,targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return Path(root,0,targetSum);
    }
};
