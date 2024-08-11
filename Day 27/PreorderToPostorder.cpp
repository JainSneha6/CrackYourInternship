class Solution {
  private:
    Node* build(int pre[], int& index, int size, int low, int high ){
        if(index>=size){
            return NULL;
        }
        int val = pre[index];
        if(val>low && val<high){
            Node* root = newNode(val);
            index++;
            
            root->left = build(pre,index,size,low,val);
            root->right = build(pre,index,size,val,high);
            
            return root;
        }
        return NULL;
    }
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        int index=0;
        return build(pre,index,size,INT_MIN,INT_MAX);
    }
};
