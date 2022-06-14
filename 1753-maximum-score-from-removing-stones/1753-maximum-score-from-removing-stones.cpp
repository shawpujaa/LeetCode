class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int cnt=0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while(pq.size()>1)
        {
            int largest=pq.top();  
            pq.pop();
            
            int second_largest=pq.top();
            pq.pop();
            
            cnt++;
            if(largest>1)
            pq.push(largest-1);
            if(second_largest>1)
            pq.push(second_largest-1);
        }
        
        return cnt;
    }
};