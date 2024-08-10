class Solution{
    private:
    Node* lca(Node* root, int a, int b){
        if(root==NULL||root->data==a||root->data==b){
            return root;
        }
        Node* left = lca(root->left,a,b);
        Node* right = lca(root->right,a,b);
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        return root;
    }
    int finddist(Node* root, int val, int dist){
        if(root==NULL){
            return -1;
        }
        if(root->data==val){
            return dist;
        }
        int leftdist = finddist(root->left,val,dist+1);
        if(leftdist!=-1){
            return leftdist;
        }
        return finddist(root->right,val,dist+1);
    }
    public:
    
    int findDist(Node* root, int a, int b) {
        Node* l = lca(root,a,b);
        int distA = finddist(l,a,0);
        int distB = finddist(l,b,0);
        return distA+distB;
    }
};
