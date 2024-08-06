class Solution{
  private:
    bool solve(Node* root, int low, int high){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(low==high){
                return true;
            }
            else{
                return false;
            }
        }
        return solve(root->left,low,root->data-1)||solve(root->right,root->data+1,high);
    }
  public:
    bool isDeadEnd(Node *root)
    {
        return solve(root,1,1e9);
    }
};
