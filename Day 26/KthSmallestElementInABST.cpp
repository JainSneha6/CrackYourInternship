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
    int ksmall(TreeNode* root,int k, int& count){
        if(root==NULL){
            return -1;
        }
        int curr = ksmall(root->left,k,count);
        if(curr!=-1){
            return curr;
        }
        count++;
        if(count==k){
            return root->val;
        }
        return ksmall(root->right,k,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return ksmall(root,k,count);
    }
};
