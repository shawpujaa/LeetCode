class LRUCache {
public:
    class node
    {
        public:
        int key;
        int val;
        node *next=0;
        node *prev=0;
        node(int keyy, int vall)
        {
            key=keyy;
            val=vall;
        }
    };
    
    node *head=new node(-1, -1);
    node *tail=new node(-1, -1);
    
    unordered_map<int, node*> mpp;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void moveToFront(node *temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
            
        temp->prev=head;
        temp->next=head->next;
        head->next=temp;
        temp->next->prev=temp;
    }
    
    int get(int key) {
        
        if(mpp.find(key)!=mpp.end())
        {
            node *temp=mpp.find(key)->second;
            moveToFront(temp);
            
            return temp->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key)!=mpp.end())
        {
            node *temp=mpp.find(key)->second;
            temp->val=value;
            
            moveToFront(temp);
        }
        else
        {
            node *temp=new node(key, value);
            temp->prev=head;
            temp->next=head->next;
            head->next=temp;
            temp->next->prev=temp;
            
            mpp[key]=temp;
            if(mpp.size()>cap)
            {
                mpp.erase(tail->prev->key);
                tail->prev->prev->next=tail;
                tail->prev=tail->prev->prev;
            }
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */