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
int solveusingTab(int n,int k,int target){
    //step1 create dp array initialize
    //step2 analyze the base case and fill the case
    //step 3 reverse flow for loop copy paste recurive call looping variable
    //step 4 return jao at recursivecalll
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int a=1;a<=n;a++){
        for(int t=1;t<=target;t++){
            long long int ans=0;
    for(int i=1;i<=k;i++){
        if(t-i>=0)
        ans=(ans%mod+dp[a-1][t]%mod)%mod;
    }
        dp[a][t]=ans;

        }
    }
    return dp[n][target];

}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        int ans=solveusingmem(n,k,target,dp);
        return ans;
        
    }
};