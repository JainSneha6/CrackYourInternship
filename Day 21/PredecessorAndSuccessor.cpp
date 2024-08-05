class Solution
{
    private:
    void pred(Node* root, Node*& pre, int key){
        pre=NULL;
        while(root!=NULL){
            if(root->key>=key){
                root=root->left;
            }
            else{
                pre=root;
                root=root->right;
            }
        }
    }
    void succ(Node* root, Node*& suc, int key){
        suc=NULL;
        while(root!=NULL){
            if(root->key<=key){
                root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pred(root,pre,key);
        succ(root,suc,key);
    }
};
