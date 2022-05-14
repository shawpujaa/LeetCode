/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *copyhead=0, *copytemp=0, *temp=head, *nextt=0;
       
        while(temp)
        {
            Node *ptr=new Node(temp->val);
            nextt=temp->next;
            temp->next=ptr;
            ptr->next=nextt;
            
            if(!copyhead)
                copyhead=ptr;
            temp=nextt;
        }
        
        temp=head;
        copytemp=copyhead;
        while(temp)
        {
            if(temp->random)
                copytemp->random=temp->random->next;
            
            temp=copytemp->next;
            if(temp)
            copytemp=temp->next;
        }
        
        temp=head;
        copytemp=copyhead;
        while(temp)
        {
            temp->next=copytemp->next;
            temp=temp->next;
            if(temp)
            {
                copytemp->next=temp->next;
                copytemp=copytemp->next;
            }
        }
        
        return copyhead;
    }
};