/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    long long path(TreeNode* root, long long targetSum, unordered_map <long long,long long>& m, long long currsum){
        if(root==NULL){
            return 0;
        }
        currsum+=root->val;
        long long num = m[currsum-targetSum];
        m[currsum]+=1;
        long long res = num + path(root->left,targetSum,m,currsum) + path(root->right,targetSum,m,currsum);
        m[currsum]-=1;
        return res;
    }
public:
    long long pathSum(TreeNode* root, long long targetSum) {
        unordered_map <long long,long long> m;
        m[0]=1;
        return path(root,targetSum,m,0);
    }
};
