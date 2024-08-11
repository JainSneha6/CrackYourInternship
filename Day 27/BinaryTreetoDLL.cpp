class Solution {
  private:
    Node* prev = NULL;
    void convert(Node* root, Node*& head){
        if(root==NULL){
            return ;
        }
        convert(root->left,head);
        if(prev==NULL){
            head=root;
        }
        else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        convert(root->right,head);
    }
  public:
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        convert(root,head);
        return head;
    }
};
