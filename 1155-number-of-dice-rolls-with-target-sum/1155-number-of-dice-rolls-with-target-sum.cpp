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
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>>dp(n+1,vector<long long  int>(target+1,-1));
        int ans=solveusingmem(n,k,target,dp);
        return ans;
    }
};