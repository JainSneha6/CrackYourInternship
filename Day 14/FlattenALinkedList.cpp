Node* merge(Node *l1, Node *l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            temp->child = l1;
            temp = l1;
            l1 = l1->child;
        } else {
            temp->child = l2;
            temp = l2;
            l2 = l2->child;
        }
    }
    if(l1){
        temp->child=l1;
    }
    else{
        temp->child=l2;
    }
    return dummy->child;
}

Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *mergehead = flattenLinkedList(head->next);
    return merge(mergehead, head);
}
