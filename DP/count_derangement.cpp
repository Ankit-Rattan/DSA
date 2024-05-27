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


long long int solveTab( int n){
    vector<long long int>dp(n+1,0);
    
    dp[1] = 0;
    dp[2] = 1;
    for(auto i = 3; i<=n; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first + second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;
        dp[i]= ans;
    }
    return dp[n];

}

long long int countDerangements(int n) {
    vector<long long int>dp(n+1, -1);
    return solveMem(dp, n);
    return solveTab(n);
}



// Space Optimized

long long int SpaceOpt( int n){
    
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(auto i = 3; i<=n; i++){
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum = (first + second)%MOD;

        long long int ans = ((i-1)*sum)%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;

}
