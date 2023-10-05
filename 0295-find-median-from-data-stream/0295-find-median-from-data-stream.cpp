class MedianFinder {
public:
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        if(s.size()==0){
            s.push(x);
            return;
        }
        
        if(s.size()>g.size()){
            if(x<s.top()){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else{
                g.push(x);
            }
        }
        else{
            if(x<s.top()){
                s.push(x);
            }
            else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
        if(s.size()==g.size()){
            return (double)(s.top()+g.top())/2.0;
        }
        else{
            return s.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */