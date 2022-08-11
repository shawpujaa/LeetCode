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
  /*  ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *nxtt=0, *prev=0;
        
        while(head)
        {
            nxtt=head->next;
            head->next=prev;
            prev=head;
            head=nxtt;
        }
        
        return prev;
            
    }  */
    
    // Recursive soln
    ListNode *newHead=0;
    
    ListNode* reverseList(ListNode *head, ListNode *prev=0)
    {
        if(!head)
            return newHead;
        
        if(!head->next)
            newHead=head;
        
        ListNode *nxtt=head->next;
        head->next=prev;
        
        return reverseList(nxtt, head);
    }
};