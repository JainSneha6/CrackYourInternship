/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    void merge(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            ListNode* node=head1->next;
            head1->next=head2;
            head1=head2;
            head2=node;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* head1=head;
        ListNode* mid=middle(head);
        ListNode* head2=reverse(mid->next);
        mid->next=NULL;
        merge(head1,head2);
    }
};
