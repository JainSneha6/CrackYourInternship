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
    bool isSameTree(TreeNode* m, TreeNode* n){
        if(m==NULL || n==NULL){
            return m==n;
        }
        return m->val==n->val && isSameTree(m->left,n->right) && isSameTree(m->right,n->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left,root->right);
    }
};
