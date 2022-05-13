class MyCircularDeque {
public:
    vector<int> dq;
    int n;
    MyCircularDeque(int k) {
        n=k;
    }
    
    bool insertFront(int value) {
        if(n)
        {
            dq.insert(dq.begin(), value); 
            n--;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(n)
        {
            dq.push_back(value); 
            n--;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(dq.size())
        {
            dq.erase(dq.begin());
            n++;
            return true;
        }
        
        return false;
    }
    
    bool deleteLast() {
        if(dq.size())
        {
            dq.erase(dq.end()-1);
            n++;
            return true;
        }
        
        return false;
    }
    
    int getFront() {
        if(dq.size())
        return dq[0];
        
        return -1;
    }
    
    int getRear() {
        if(dq.size())
        return dq[dq.size()-1];
        
        return -1;
    }
    
    bool isEmpty() {
        if(dq.empty())
            return true;
        
        return false;
    }
    
    bool isFull() {
        if(n==0)
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */