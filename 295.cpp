class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        int s1 = l.size(), s2 = r.size();
        if (s1 == s2) {
            if (r.empty() || num <= r.top()) l.push(num);
            else {
                l.push(r.top()); r.pop();
                r.push(num);
            }
        } else {
            if (l.top() <= num) r.push(num);
            else {
                r.push(l.top()); l.pop();
                l.push(num);
            }
        }
    }
    
    double findMedian() {
        int s1 = l.size(), s2 = r.size();
        if (s1 == s2) return (l.top() + r.top()) / 2.0;
        return l.top();
    }
private:
    priority_queue<int> l; // smaller, max heap
    priority_queue<int, vector<int>, greater<int>> r; // bigger, min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
