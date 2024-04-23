// disc | T:O(M*N) | S:O(M*N)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int INF = INT_MAX;
        int m = rooms.size(), n = rooms[0].size();

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) { // door: dest
                    q.emplace(i, j, 0); // q.push(tuple<int, int, int>{r, c, 0})
                }
            }
        }

        while (q.size()) {
            auto [r, c, dist] = q.front(); q.pop();
            for (auto [dr, dc] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int nr = r + dr;
                int nc = c + dc;
                if (0 <= nr && nr < m && 0 <= nc && nc < n && rooms[nr][nc] == INF) { // empty room: src
                    rooms[nr][nc] = dist + 1;
                    q.emplace(nr, nc, dist + 1);
                }
            }
        }
    }
};
