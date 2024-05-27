#define MOD 1000000007
#include<vector>

long long int solveMem(vector<long long int>&dp, int n){

    // base case : 
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] !=-1) return dp[n];

    dp[n] = (   ((n-1)%MOD)* ( (solveMem(dp,n-1)%MOD)
                                    + (solveMem(dp,n-2)%MOD)))%MOD;
    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int>dp(n+1, -1);
    return solveMem(dp, n);
}