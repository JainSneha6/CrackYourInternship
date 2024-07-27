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
    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
            if(temp1){
                temp->next=temp1;
            }
            if(temp2){
                temp->next=temp2;
            }
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* head1=head;
        ListNode* middle=mid(head);
        ListNode* head2=middle->next;
        middle->next=NULL;

        head1=sortList(head1);
        head2=sortList(head2);

        return merge(head1,head2);
    }
};
