/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* segregateEvenOdd(Node* head)
{
    Node* evenHead = new Node(-1);
    Node* oddHead = new Node(-1);

    Node* even = evenHead;
    Node* odd = oddHead;

    Node* temp = head;

    while(temp){
        if(temp->data%2==0){
            even->next=temp;
            even=even->next;
        }
        else{
            odd->next=temp;
            odd=odd->next;
        }
        temp=temp->next;
    }

    even->next=oddHead->next;
    odd->next=NULL;

    Node* newHead = evenHead->next;

    delete evenHead;
    delete oddHead;

    return newHead;
}
