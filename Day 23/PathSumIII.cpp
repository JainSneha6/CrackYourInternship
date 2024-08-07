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
    int path(TreeNode* root, int targetSum, unordered_map <int,int>& m, int currsum){
        if(root==NULL){
            return 0;
        }
        currsum+=root->val;
        int num = m[currsum-targetSum];
        m[currsum]+=1;
        int res = num + path(root->left,targetSum,m,currsum) + path(root->right,targetSum,m,currsum);
        m[currsum]-=1;
        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map <int,int> m;
        m[0]=1;
        return path(root,targetSum,m,0);
    }
};
