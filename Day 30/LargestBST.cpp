class Solution{
    private:
    struct Info{
        int size;
        int max;
        int min;
        int maxSize;
        bool isBST;
    };
    Info largestBST(Node* root){
        if(root==NULL){
            return {0,INT_MIN,INT_MAX,0,true};
        }
        if(root->left==NULL && root->right==NULL){
            return {1,root->data,root->data,1,true};
        }
        
        Info leftInfo = largestBST(root->left);
        Info rightInfo = largestBST(root->right);
        
        Info curr;
        curr.size = 1+leftInfo.size+rightInfo.size;
        
        if(leftInfo.isBST && rightInfo.isBST && root->data>leftInfo.max && root->data<rightInfo.min){
            curr.min = min(root->data,leftInfo.min);
            curr.max = max(root->data,rightInfo.max);
            
            curr.maxSize=curr.size;
            curr.isBST = true;
        }
        else{
            curr.isBST = false;
            curr.maxSize = max(leftInfo.maxSize,rightInfo.maxSize);
        }
        return curr;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBST(root).maxSize;
    }
};
