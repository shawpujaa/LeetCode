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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *new_head=0;
        int n=lists.size();
        
        if(n==1)
            return lists[0];
        
        if(n==0)
            return new_head;
        
        for(int i=1;i<n;i++)
        {
            ListNode *temp1=0, *temp2=0, *prev=0;
            if(new_head)
                temp1=new_head;
            else
                temp1=lists[i-1];
            
            temp2=lists[i];
            
            while(temp1 && temp2)
            {
                if(temp1->val > temp2->val)
                {
                    if(prev!=0)
                        prev->next=temp2;
                    
                    prev=temp2;
                    temp2=temp2->next;
                }
                else
                {
                    if(prev!=0)
                        prev->next=temp1;
                    
                    prev=temp1;
                    temp1=temp1->next;
                }
                
                if(!new_head || prev->val<new_head->val)
                    new_head=prev;
            }
            
            if(temp2)
            {
                if(prev)
                    prev->next=temp2;
                else
                {
                    new_head=temp2;
                }
            }
            
            if(temp1)
            {
                if(prev)
                    prev->next=temp1;
                else
                {
                    new_head=temp1;
                }
            }
            
        }
       
        return new_head;
    }
};