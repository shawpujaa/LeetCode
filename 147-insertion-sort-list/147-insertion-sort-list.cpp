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
        if(!head || !head->next)
            return head;
        
        ListNode *temp=head->next, *prev=head, *ptr=head;
        
        while(temp)
        {
            if(temp->val >= prev->val)
            {
                prev=temp;
                temp=temp->next;
                continue;
            }
            
            while(ptr->val <= temp->val && ptr->next->val <= temp->val)
            ptr=ptr->next;
            
            prev->next=temp->next;
            if(ptr==head && ptr->val > temp->val)
            {
                head=temp;
                temp->next=ptr;
            }
            else
            {
                temp->next=ptr->next;
                ptr->next=temp;
            }
            ptr=head;
            temp=prev->next;
        }
        
        return head;
    }
};