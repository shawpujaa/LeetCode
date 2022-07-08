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
public:// Method 1 using random function over the list..O(N)
   /* 
    int size=0;
    ListNode *Head=0;
    Solution(ListNode* head) {
        Head=head;
        
        while(head)
        {
            size++;
            head=head->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%size;
        ListNode *curr=Head;
        
        while(idx--)
            curr=curr->next;
        
        return curr->val;
    }  */
    
    // ---follow up when size is large;
    
    ListNode *Head=0;
    Solution(ListNode* head) {
        Head=head;
    }
    
    int getRandom() {
        ListNode *curr=Head;
        int ans=0, idx=1;
        
        while(curr)
        {
            if(rand()%idx==0)
                ans=curr->val;
            
            idx++;
            curr=curr->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */