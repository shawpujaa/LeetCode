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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head->next)
            return head;
        
        ListNode *temp=head, *new_head=0, *prev=0, *next=0, *prev2=0;
        int n=0;
        
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        
        temp=head;
        n=n/k;
        while(n--)
        {
            int x=k;
            
            while(x--)
            {
                next=temp->next;
                temp->next=prev;
                prev=temp;
                
                temp=next;
            }
           
            if(prev2)
                prev2->next=prev;
            
            if(!new_head)
                new_head=prev;
            
            while(prev->next)
                prev=prev->next;
            
            prev2=prev;
            prev=0;
        }
        
        prev2->next=temp;
        
        if(new_head)
            return new_head;
        
        return head;
    }
};