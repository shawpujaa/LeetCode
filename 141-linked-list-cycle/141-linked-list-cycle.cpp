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
    bool hasCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
    
            if(fast)
                fast=fast->next;
            
            if(fast==slow && fast)
                return true;
        }
        
        return false;
            
    }
};