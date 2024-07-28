public:
    Node* zigZag(Node* head) {
        bool flag=true;
        Node* temp=head;
        while(temp && temp->next){
            if(flag){
                if(temp->data>temp->next->data){
                    swap(temp->data,temp->next->data);
                }
            }
            else{
                if(temp->data<temp->next->data){
                    swap(temp->data,temp->next->data);
                }
            }
            flag=!flag;
            temp=temp->next;
        }
        return head;
    }
