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
    void leafSum(TreeNode* root, bool isLeft, int& sum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL && isLeft){
            sum+=root->val;
        }
        leafSum(root->left,true,sum);
        leafSum(root->right,false,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        leafSum(root,false,ans);
        return ans;
    }
};
