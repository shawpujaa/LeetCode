class MyQueue {
public:
    stack<int> smain;
    stack<int> saux;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        smain.push(x);
        
    }
    
    int pop() {
        int x;
        
        while(!smain.empty())
        {
            saux.push(smain.top());
            smain.pop();
        }
        
        x=saux.top();
        saux.pop();
        
        while(!saux.empty())
        {
            smain.push(saux.top());
            saux.pop();
        }
        
        return x;
        
    }
    
    int peek() {
        int x;
        
        while(!smain.empty())
        {
            saux.push(smain.top());
            smain.pop();
        }
        
        x=saux.top();
        
        while(!saux.empty())
        {
            smain.push(saux.top());
            saux.pop();
        }
        
        return x;
        
    }
    
    bool empty() {
        if(smain.empty())
            return true;
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */