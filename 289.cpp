// bitmap | T:O(MN) | S:O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                int sum = 0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                        sum += (board[nx][ny]&1); // only sum lowest bit
                    }
                }
                if(board[i][j] == 1) {
                    if(sum == 2 || sum == 3) {
                        board[i][j] |= 2;  // mark 2nd bit: status
                    }
                } else {
                    if(sum == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1; // move right 1 bit, overwrite
            }
        }
    }
};


// brute force | T:O(MN) | S:O(MN)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        newBoard(b);
    }
private:
    void newBoard(vector<vector<int>>& b) {
        int m = b.size(), n = b[0].size();
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = neighbor(b, i, j);
                if (cnt < 2) tmp[i][j] = 0;
                else if (cnt == 3 && b[i][j] == 0) tmp[i][j] = 1;
                else if (cnt > 3 && b[i][j] == 1) tmp[i][j] = 0;
                else tmp[i][j] = b[i][j];
            }
        }
        copyBoard(b, tmp);
    }
    void copyBoard(vector<vector<int>>& b, vector<vector<int>>& tmp) {
        int m = b.size(), n = b[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                b[i][j] = tmp[i][j];
            }
        }
    }
    int neighbor(vector<vector<int>>& b, int i, int j) {
        int cnt = 0;
        for (int x = i - 1; x <= i + 1; ++x) {
            for (int y = j - 1; y <= j + 1; ++y) {
                if (x != i || y != j) {
                    cnt += check(b, x, y) ? 1 : 0;
                }
            }
        }
        return cnt;
    }
    bool check(vector<vector<int>>& b, int i, int j) {
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] == 0) return 0;
        return 1;     
    }
};
