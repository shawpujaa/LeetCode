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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head->next)
            return head;
        
        ListNode *headptr=head, *temp=head->next, *prev=head;
        
        while(temp)
        {
            
            if(prev->val <= temp->val)
            {
                prev=temp;
                temp=temp->next;
                continue;
            }
            
            if(headptr->val > temp->val)
            {
                prev->next=temp->next;
                temp->next=headptr;
                
                headptr=temp;
                head=temp;
                temp=prev->next;
                continue;
            }
            
            while(headptr->val < temp->val && headptr->next->val <= temp->val)
            {
                headptr=headptr->next;
            }
           
            prev->next=temp->next;
            temp->next=headptr->next;
            headptr->next=temp;
                
            temp=prev->next;
            headptr=head;
           
        }
        
        return head;
    }
};