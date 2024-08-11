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
    int height(TreeNode* root, int& maxi){
        if(root==NULL){
            return 0;
        }
        int lps=max(0,height(root->left,maxi));
        int rps=max(0,height(root->right,maxi));
        maxi=max(maxi,lps+rps+root->val);
        return max(lps,rps)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }
};
