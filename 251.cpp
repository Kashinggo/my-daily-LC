// my submission | T: O(1) | S: O(N)

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) : idx(0) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                v1d.push_back(vec[i][j]);
            }
        }
    }
    
    int next() {
        return v1d[idx++];
    }
    
    bool hasNext() {
        return idx < v1d.size();
    }
private:
    int idx;
    vector<int> v1d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


// follow-up, use only iter, not loop | T: O(1) | S: O(1)
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) : y(0), x(vec.begin()), end(vec.end()){
    }
    
    void moveToNextPos() {
        while (x != end && y == (*x).size()) { // key point
            ++x; 
            y = 0;
        }
    }

    int next() {
        moveToNextPos();
        return (*x)[y++];
    }
    
    bool hasNext() {
        moveToNextPos();
        return x != end && y < (*x).size();
    }
private:
    int y;
    vector<vector<int>>::iterator x;
    vector<vector<int>>::iterator end;
};
