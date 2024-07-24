private:
    Node* reverse(Node* head){
        Node* temp=head;
        Node* prev=NULL;
        while(temp){
            Node* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        head=reverse(head);
        
        int maxi=head->data;
        Node* temp=head;
        while(temp && temp->next){
            if(temp->next->data<maxi){
                Node* delnode=temp->next;
                temp->next=temp->next->next;
                delete delnode;
            }
            else{
                maxi=temp->next->data;
                temp=temp->next;
            }
        }
        
        head=reverse(head);
        
        return head;
    }
