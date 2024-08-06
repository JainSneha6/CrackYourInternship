/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& m){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*,TreeNode*> m;
        markParents(root,m);

        unordered_map <TreeNode*,bool> vis;
        queue <TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int size = q.size();
            if(level++==k){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(m[node] && !vis[m[node]]){
                    vis[m[node]]=true;
                    q.push(m[node]);
                }
            }
        }
        vector <int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
