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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && list2)
            return list2;
        else if(list1 && !list2)
            return list1;
        else if(!list1 && !list2)
            return 0;
        
        ListNode *newHead=0, *prev=0;
        
        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                if(prev)
                    prev->next=list2;
                else
                    newHead=list2;
                
                prev=list2;
                list2=list2->next;
            }
            else
            {
                if(prev)
                    prev->next=list1;
                else
                    newHead=list1;
                
                prev=list1;
                list1=list1->next;
            }
        }
        
        if(list1)
            prev->next=list1;
        
        if(list2)
            prev->next=list2;
        
        return newHead;
    }
};