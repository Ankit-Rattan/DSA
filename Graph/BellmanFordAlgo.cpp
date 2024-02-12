vector<int> bellmonFord(int n, int m, int src,int des,  vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dis(n+1,1e8);
    dis[src] = 0;

    // n-1 times
    for(auto i = 1; i<=n; i++){
        // Traverse on edge
        for(auto j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dis[u] != 1e8 and (dis[u] + w) < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    // check for negative cycle

    bool flag = 0;
    for(auto j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w =edges[j][2];
        if(dis[u] != 1e8 and (dis[u] + w) < dis[v]){
            flag = 1;
        }
    }
    if(flag){
        return -1;
    }

    return dis[des];
}