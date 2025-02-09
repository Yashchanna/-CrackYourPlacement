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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next  or k==0)
        {
            return head;
        }

        ListNode* tail = head;
        int length = 1;
        while(tail->next)
        {
            tail=tail->next;
            length++;
        }

        k = k%length;
        if(k==0) return head;

        int pos = length-k;
        ListNode* newtail = head;

        while(pos!=1)
        {
            newtail=newtail->next;
            pos--;
        }

        ListNode* newhead = newtail->next;
        tail->next=head;
        newtail->next = NULL;

        return newhead;
    
    }
};