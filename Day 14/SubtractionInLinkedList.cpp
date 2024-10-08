class Solution {
public:
   Node* reverseList(Node* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        Node* prev = NULL;
        Node* current = head;
        Node* next = current->next;
        while(current!=NULL)
        {
            current->next = prev;
            prev = current;
            current = next;
            if(next!=NULL)
            {
                next = next->next;
            }
        }
        head = prev;
        return head;
   }
   int length(Node* head){
       int len = 0;
       while(head){
           len++;
           head = head->next;
       }
       return len;
   }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        //eliminating 0's
        while(head1 && head1->data == 0){
            head1 = head1->next;
        }
        while(head2 && head2->data == 0){
            head2 = head2->next;
        }
        
        if(!head1 && !head2){
            Node* head = new Node(0);
            return head;
        }
        
        int n1 = length(head1);
        int n2 = length(head2);
        if(n2>n1){
            swap(head1,head2);
        }
        if(n1 == n2){
            Node* temp1 = head1,*temp2 = head2;
            while(temp1->data == temp2->data){
                temp1 = temp1->next;
                temp2 = temp2->next;
                if(!temp1){
                    return new Node(0);
                }
            }
            if(temp2->data > temp1->data){
                swap(head1,head2);
            }
        }
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        Node* newList = NULL;
        Node* last = NULL;
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1){
            int small = 0;
            if(temp2){
                small = temp2->data;
            }
            if(temp1->data<small){
                temp1->next->data = temp1->next->data - 1;
                temp1->data = temp1->data + 10;
            }
            Node* newNode = new Node(temp1->data - small);
            if(newList == NULL){
                newList  = newNode;
                last = newNode;
            }else{
                last->next = newNode;
                last = last->next;
            }
            temp1 = temp1->next;
            if(temp2){
                temp2 = temp2->next;
            }
        }
        newList = reverseList(newList);
        while(newList && newList->data == 0){
            newList = newList->next;
        }
        return newList;
    }
};
