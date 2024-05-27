#include <bits/stdc++.h> 
#define MOD  1000000007

int add(int a, int b){
    return ((a%MOD) + (b%MOD))%MOD;
}

int mult(int a, int b){
    return ((a%MOD)*1LL * (b%MOD)) %MOD;
    // 1LL -> for range issue
}   

int solveMem(int n, int k, vector<int>&dp){
    // base case: 
    if(n == 1) return k;
    if(n == 2) return add(k, mult(k, k-1));

    if(dp[n] != -1) return dp[n];

    dp[n] = add(mult(solveMem(n-2,k, dp),k-1), mult(solveMem(n-1,k, dp), k-1));

    return dp[n];
}
int solveTab(int n, int k){
    vector<int>dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, mult(k, k-1));

    for(auto i = 3; i<=n; i++){
        dp[i] = add(mult(dp[i-2],k-1), mult(dp[i-1], k-1));
    }
    return dp[n];
}

// Space Optimized

int spaceOpt(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mult(k, k-1));
    for(auto i = 3; i<=n; i++){
        int curr = add(mult(prev1, k-1), mult(prev2, k-1));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solveMem(n, k, dp);
}
