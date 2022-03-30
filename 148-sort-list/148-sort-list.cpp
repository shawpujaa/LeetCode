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
    void divide(ListNode* &left, ListNode* &right, ListNode *temp)
    {
        ListNode *slow=temp, *fast=temp;
        
        while(fast->next)
        {
            fast=fast->next;
            
            if(fast->next)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        
        left=temp;
        right=slow->next;
        slow->next=0;
    }
    
    ListNode* merge(ListNode *left, ListNode *right)
    {
        if(!left)
            return right;
        
        if(!right)
            return left;
        
        ListNode *new_head=0;
        
        if(left->val > right->val)
        {
            new_head=right;
            new_head->next=merge(left, right->next);
        }
        else
        {
            new_head=left;
            new_head->next=merge(right, left->next);
        }
        
        return new_head;
    }
    
    ListNode* sortList(ListNode* head) {
       
        if(!head || !head->next)
            return head;
        
        ListNode *left=0, *right=0;
        
        divide(left, right, head);
        
        left=sortList(left);
        right=sortList(right);
        
        head=merge(left, right);
        
        return head;
    }
};