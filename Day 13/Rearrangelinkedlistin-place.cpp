class Solution {
  private:
    Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            Node* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* mid(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
  public:
    Node *inPlace(Node *root) {
        Node* head1=root;
        Node* middle=mid(root);
        Node* head2=middle->next;
        middle->next=NULL;
        head2=reverse(head2);
        
        Node* head = new Node(-1);
        Node* temp = head;
        while(head1 || head2){
            if(head1){
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
            if(head2){
                temp->next=head2;
                temp=temp->next;
                head2=head2->next;
            }
        }
        return head->next;
    }
};
