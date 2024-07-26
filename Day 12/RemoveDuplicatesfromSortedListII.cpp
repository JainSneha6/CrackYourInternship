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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* curr=head;
        while(curr){
            bool flag=false;
            while(curr->next && curr->val==curr->next->val){
                flag=true;
                curr=curr->next;
            }
            if(flag){
                temp->next=curr->next;
            }
            else{
                temp=temp->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
