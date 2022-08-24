class MedianFinder {
private:
    priority_queue<int> left; //1
    priority_queue<int, vector<int>, greater<int>> right; // 2
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(left.empty() )
        {
            left.push(num);
            return;
        }
        else
        {
            if(num < left.top())
                left.push(num);
            else
                right.push(num);
        }
        if( left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian()
    {
        if(left.size() == right.size())
        {
            if(left.size() == 0)
                return (double) 0.0;
            else
                return (right.top() + left.top()) / 2.0;
        }
        else
            return left.size() > right.size() ?
                   left.top() : right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
