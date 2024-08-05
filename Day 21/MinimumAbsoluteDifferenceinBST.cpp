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
    void inorder(TreeNode* root, int& prev, int& mindiff){
        if(root==NULL){
            return;
        }
        inorder(root->left,prev,mindiff);
        if(prev!=-1){
            mindiff=min(mindiff,root->val-prev);
        }
        prev=root->val;
        inorder(root->right,prev,mindiff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mindiff=INT_MAX;
        int prev=-1;
        inorder(root,prev,mindiff);
        return mindiff;
    }
};
