#include <bits/stdc++.h> 

// Recursive Approach ONLY
int solve(vector<int> &weight, vector<int> &value, int ind, int capacity){
	
	// base case:
	if(ind == 0){
		if(weight[0] <= capacity) return value[0];
		else return 0;
	}

	int include = 0;
	if(weight[ind] <= capacity){
		include = value[ind] + solve(weight, value, ind-1, capacity-weight[ind]);
	}
	int exclude = 0 + solve(weight, value, ind-1, capacity);

	int ans = max(exclude, include);
	return ans;
}

// Memoization
int solveMem(vector<int> &weight, vector<int> &value, int ind, int capacity,vector<vector<int>>&dp){
	
	// base case:
	if(ind == 0){
		if(weight[0] <= capacity) return value[0];
		else return 0;
	}
	if(dp[ind][capacity] != -1) 
		return dp[ind][capacity];
	
	int include = 0;
	if(weight[ind] <= capacity){
		include = value[ind] + solveMem(weight, value, ind-1, capacity-weight[ind], dp);
	}
	int exclude = 0 + solveMem(weight, value, ind-1, capacity, dp);

	dp[ind][capacity] = max(exclude, include);
	return dp[ind][capacity];
}

// Tabulation
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
	
	// step:1 - make dp array
	vector<vector<int>>dp(n, vector<int>(capacity+1, 0));

	// step:2 - analyse base case:
	for(auto w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity)
			dp[0][w] = value[0];
		else	
			dp[0][w] = 0;	
	}

	// Step:3 -	
	for(auto i = 1; i<n; i++){
		for(auto w = 0; w<=capacity; w++){

				int include = 0;
				if(weight[i] <= w)
					include = value[i] + dp[i-1][w-weight[i]];
			
				int exclude = 0 + dp[i-1][w];

				dp[i][w] = max(exclude, include);
		}
	}

	return dp[n-1][capacity];
	
}

// Space Optimized 
// dp[n] depends on dp[n-1] --> No need to create whole matrix, just create two vectors represents dp[n] and dp[n-1].
int solveSpaceOpt(vector<int> &weight, vector<int> &value, int n, int capacity){
	
	// step:1 - make two array
	vector<int>prev(capacity+1, 0);
	vector<int>curr(capacity+1, 0);

	// step:2 - analyse base case:
	for(auto w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity)
			prev[w] = value[0];
		else	
			prev[w] = 0;	
	}

	// Step:3 -	
	for(auto i = 1; i<n; i++){
		for(auto w = 0; w<=capacity; w++){

				int include = 0;
				if(weight[i] <= w)
					include = value[i] + prev[w-weight[i]];
			
				int exclude = 0 + prev[w];

				curr[w] = max(exclude, include);
		}
		prev = curr;
	}

	return prev[capacity];
	
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// solve(weight, value, n-1, maxWeight);

	// vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	// return solveMem(weight, value, n-1, maxWeight, dp);

	// return solveTab(weight, value, n, maxWeight);
    
	return solveSpaceOpt(weight, value, n, maxWeight);

}