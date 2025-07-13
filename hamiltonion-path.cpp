class Solution {
  public:
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
           vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u][v] = true;
        adj[v][u] = true;
    }

    // Generate all permutations of nodes
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = i + 1;
    }

    do {
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if (!adj[nodes[i - 1]][nodes[i]]) {
                valid = false;
                break;
            }
        }
        if (valid) return true;
    } while (next_permutation(nodes.begin(), nodes.end()));

    return false;
    }
};
