#include <unordered_map>
#include <list>
#include <vector>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &res, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    disc[node] = timer++;
    low[node] = disc[node];

    for (auto i : adj[node]) {
        if (i == parent) {
            continue;
        }
        if (!vis[i]) {
            dfs(i, node, timer, disc, low, res, vis, adj);
            low[node] = min(low[node], low[i]);

            // check edge is bridge
            if (low[i] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(i);
                res.push_back(ans);
            }
        } else {
            // Backedge
            low[node] = min(low[node], disc[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (auto i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for (auto i = 0; i < v; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> res;
    // dfs
    for (auto i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, parent, timer, disc, low, res, vis, adj);
        }
    }
    return res;
}
