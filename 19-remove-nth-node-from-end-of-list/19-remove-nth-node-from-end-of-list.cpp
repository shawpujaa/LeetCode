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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode *temp=head;
        
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        
        if(cnt==n)
            return head->next;
        
        temp=head;
        cnt-=(n+1);
        
        while(cnt--)
            temp=temp->next;
        cout<<temp->val;
        temp->next=temp->next->next;
        
        return head;
    }
};