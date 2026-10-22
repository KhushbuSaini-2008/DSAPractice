class Solution {
public:
long long int mod=1000000007;
// int solveusingRec(int n, int k, int target){
//     //base case
//     if(n==0 && target==0){
//         return 1;
//     }
//     if(n<0 && target<0){
//         return 0;
//     }
//     if(n!=0 &&target==0){
//         return 0;
//     }
//     if(n==0 && target!=0 ){
//         return 0;
//     }
//     long long int ans=0;
//     for(int i=1;i<=k;i++){
//         ans=(ans%mod+solveusingRec(n-1,k,target-i)%mod)%mod;
//     }
// return ans;
// }
// dp
int solveusingmem(int n,int k,int target,vector<vector<int>>&dp){
    //analyzethe type of dp
    //create inittialize pass receive recursive call
    //store value
    //check already exist
     if(n==0 && target==0){
        return 1;
    }
    if(n<0 && target<0){
        return 0;
    }
    if(n!=0 &&target==0){
        return 0;
    }
    if(n==0 && target!=0 ){
        return 0;
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    long long int ans=0;
    for(int i=1;i<=k;i++){
        if(target-i>=0)
        ans=(ans%mod+solveusingmem(n-1,k,target-i,dp)%mod)%mod;
    }
        dp[n][target]=ans;
return ans;

}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        int ans=solveusingmem(n,k,target,dp);
        return ans;
        
    }
};