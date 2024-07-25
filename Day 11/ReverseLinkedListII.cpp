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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||left==right){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;

        for(int i=1;i<left;i++){
            temp=temp->next;
        }

        ListNode* start = temp->next;
        ListNode* end;

        for(int i=left;i<right;i++){
            end = start->next;
            start->next = end->next;
            end->next = temp->next;
            temp->next = end;
        }
        return dummy->next;
    }
};
