/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insert(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
    }

    void connect(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = temp->next;
            if (temp->random) {
                copy->random = temp->random->next;
            } else {
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* copy(Node* head) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while (temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        insert(head);
        connect(head);
        return copy(head);
    }
};
