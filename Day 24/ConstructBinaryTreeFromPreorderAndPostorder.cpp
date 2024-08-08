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
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, unordered_map <int,int> m, int prestart, int poststart, int len){
        if(len==0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(len==1){
            return root;
        }
        int leftRoot = preorder[prestart+1];
        int leftlen = m[leftRoot]-poststart+1;
        root->left = construct(preorder,postorder,m,prestart+1,poststart,leftlen);
        root->right = construct(preorder,postorder,m,prestart+leftlen+1,poststart+leftlen,len-1-leftlen);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map <int,int> m;
        for(int i=0;i<postorder.size();i++){
            m[postorder[i]]=i;
        }
        return construct(preorder,postorder,m,0,0,preorder.size());
    }
};
