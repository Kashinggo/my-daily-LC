// discussion | O(N^2) | O(N^2) | DFS, BFS, Union Find

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if (edges.size() != n - 1) return false; // check no loop

        vector<vector<int>> graph(n, vector<int>());
        for (auto &edge : edges) {
            int a = edge[0], b= edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n, 0);
        dfs(graph, 0, visited);

        for (auto c : visited) { // check if all visited
            if (!c) return false;
        }

        return true;
    }
private:
    void dfs(vector<vector<int>> &graph, int i, vector<bool> &visited) {
        if (visited[i]) return;
        visited[i] = true;
        for (auto c : graph[i]) {
            dfs(graph, c, visited);
        }
    }
};

// my trial was blocked, cuz I didn't record and skip `lastNode` in my DFS
// `if(lastNode == i) contine;`