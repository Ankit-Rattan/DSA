#include<unordered_map>
#include<vector>
#include<stack>
void dfs(int node,unordered_map<int, bool>&vis, stack<int>&s,unordered_map<int, vector<int>>&adj){
	vis[node] = true;
	for(auto i: adj[node]){
		if(!vis[i]){
			dfs(i, vis, s, adj);
		}
	}
	s.push(node);
}
void ndfs(int node, unordered_map<int, bool>&vis,unordered_map<int, vector<int>>&tg){
	vis[node] = true;
	for(auto i: tg[node]){
		if(!vis[i]){
			ndfs(i, vis, tg);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	//Adj List
	unordered_map<int, vector<int>>adj;
	for(auto i = 0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// Topological Sort
	stack<int>s;
	unordered_map<int, bool>vis;
	for(auto i=0; i<v; i++){
		if(!vis[i]){
			dfs(i, vis, s, adj);
		}
	}

	// Transpose
	unordered_map<int, vector<int>>tg;
	for(auto i = 0 ;i<v; i++){
		vis[i] = false; // making vis false for all to use it again.
		for(auto j : adj[i]){
			tg[j].push_back(i);
		}
	}

	// DFS using above ordereing 
	int count = 0;
	while(!s.empty()){
		int top = s.top(); 
		s.pop();
		if(!vis[top]){
			count++;
			ndfs(top, vis, tg);
		}
	}
	return count;

}