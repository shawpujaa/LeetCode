/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int x=INT_MIN;
        
        while(head)
        {
            if(head->val==x)
                return head;
            
            head->val=x;
            head=head->next;
        }
        
        return 0;
    }
};