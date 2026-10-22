class Solution {
public:
// int solveusingRec(int n,int k,int target){
//     if(n<0 && target<0){
//         return 0;
//     }
//     if(n==0 && target==0){
//         return 1;
//     }
//     if(n!=0 && target==0){
//         return 0;
//     }
//     if(n==0 && target!=0){
//         return 0;
//     }
//     int ans=0;
//     for(int i=1;i<=k;i++){
//          ans=ans+solveusingRec(n-1,k,target-i);
//     }
//     return ans;
// }
long long int mod=1000000007;
int solveusingmem(int n,int k,int target,vector<vector<long long int>>&dp){
    if(n<0 || target<0){
        return 0;
    }
    if(n==0 && target==0){
        return 1;
    }
    if(n!=0 && target==0){
        return 0;
    }
    if(n==0 && target!=0){
        return 0;
    }
   long long  int ans=0;
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    for(int i=1;i<=k;i++){
        if((target-i)>=0)
         ans=(ans%mod+solveusingmem(n-1,k,target-i,dp)%mod)%mod;
    }
         dp[n][target]=ans;
    return ans;
}
// int solveuingtab(int n, int k, int target){
//     vector<vector<long long int>>dp(n+1,vector<long long  int>(target+1,0));
//     dp[0][0]=1;
//     long long int ans=0;
//     for(int a=1;a<=n;a++){
//         for(int t=1;t<=target;t++){

//             for(int i=1;i<=k;i++){
//         if((target-i)>=0)
//          ans=(ans%mod+dp[n-1][target-i]%mod)%mod;
//     }
//          dp[n][target]=ans;

//         }
//     }
//     return dp[n][target];
    
// }
int solveusingSO(int n, int k, int target){
   // vector<vector<long long int>>dp(n+1,vector<long long  int>(target+1,0));
   vector<int>prev(target+1,0);
   vector<int>curr(target+1,0);
    prev[0]=1;
    for(int a=1;a<=n;a++){
        for(int t=1;t<=target;t++){
    long long int ans=0;
            for(int i=1;i<=k;i++){
        if((t-i)>=0)
         ans=(ans%mod+prev[t-i]%mod)%mod;
    
            }
         curr[t]=ans;
            }
         prev=curr;

        }
        
    
    return curr[target];
    
}
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<long long int>>dp(n+1,vector<long long  int>(target+1,-1));
        int ans=solveusingSO(n,k,target);
        return ans;
    }
};