// disc | T: O(1) | S:O(1)
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push({v1.begin(), v1.end()});
        if (!v2.empty()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        if (!hasNext()) return -1;
        auto cur = q.front(); q.pop();
        if (cur.first + 1 != cur.second) {
            q.push({cur.first + 1, cur.second});
        }

        return *cur.first;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<pair<vector<int>::iterator, vector<int>::iterator> > q;
};


// my | T: O(N) | S:O(N)
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size();
        for (int i = 0; i < max(n1, n2); ++i) {
            if (i < n1) q.push(v1[i]);
            if (i < n2) q.push(v2[i]);
        }
    }

    int next() {
        int next = q.front(); q.pop();
        return next;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
