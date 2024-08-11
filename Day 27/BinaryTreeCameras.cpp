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
    int dfs(TreeNode* root, int& camera){
        if(root==NULL){
            return 1;
        }
        int left = dfs(root->left,camera);
        int right = dfs(root->right,camera);

        if(left==0 || right==0){
            camera++;
            return 2;
        }

        if(left==2 || right==2){
            return 1;
        }

        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int camera=0;
        dfs(root,camera);
        return camera;
    }
};
