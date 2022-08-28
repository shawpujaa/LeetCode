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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        
        ListNode *fast=head, *slow=head, *prev=0;
        
        while(fast)
        {
            prev=slow;
            fast=fast->next;
            slow=slow->next;
            
            if(fast)
                fast=fast->next;
        }
        
        ListNode *temp=slow, *prev2=0;
        
        while(temp)
        {
            ListNode *nxt=temp->next;
            temp->next=prev2;
            prev2=temp;
            temp=nxt;
        }
        
        prev->next=prev2;
        fast=head;
        slow=prev2;
        
        while(slow)
        {
            if(fast->val != slow->val)
                return false;
            
            fast=fast->next;
            slow=slow->next;
        }
            
        return true;
    }
};