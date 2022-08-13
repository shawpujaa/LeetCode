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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp=0, *head=0, *prev=0;
        int carry=0;
        
        while(l1 && l2)
        {
            temp = new ListNode((l1->val + l2->val + carry)%10);
            carry=(l1->val + l2->val + carry)/10;
            
            if(!head)
                head=temp;
            
            if(prev)
                prev->next=temp;
            
            prev=temp;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1)
        {
            temp = new ListNode((l1->val + carry)%10);
            carry=(l1->val + carry)/10;
            prev->next=temp;
            prev=temp;
            
            l1=l1->next;
        }
        
        while(l2)
        {
            temp = new ListNode((l2->val + carry)%10);
            carry=(l2->val + carry)/10;
            prev->next=temp;
            prev=temp;
            
            l2=l2->next;
        }
        
        if(carry)
        {
            temp = new ListNode(carry);
            prev->next=temp;
        }
        
        return head;
    }
};