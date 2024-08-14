Node* create(int n, int pre[], char preLN[], int &index){
    if(index>=n){
        return NULL;
    }
    
    Node* root = new Node(pre[index]);
    if(preLN[index]=='L'){
        index++;
        return root;
    }
    index++;
    root->left = create(n,pre,preLN,index);
    root->right = create(n,pre,preLN,index);
    
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int index=0;
    return create(n,pre,preLN,index);
}
