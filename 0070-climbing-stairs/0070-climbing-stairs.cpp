class Solution {
public:
// int climbStairs(int n) {
//         if(n==1|| n==2){
//             return n;
//         }
//         int ans=climbStairs(n-1)+climbStairs(n-2);
//         return ans;
//     }
    // int climbStairsmemo(int n,vector<int>dp){
    //      if(n==1|| n==2){
    //         return n;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int ans=climbStairsmemo(n-1,dp)+climbStairsmemo(n-2,dp);
    //     dp[n]=ans;
    //     return dp[n];
    // }
    //   int climbStairstabulation(int n){
    //     if(n==1||n==2){
    //         return n;
    //     }
    //     vector<int>dp(n+1,-1);
    //    dp[1]=1;
    //    dp[2]=2;
    //    for(int i=3;i<=n;i++){
    //     int ans=dp[i-1]+dp[i-2];
    //     dp[i]=ans;
    //    }
    //     return dp[n];
    // }
    int climbStairstabulation(int n){
        if(n==1||n==2){
            return n;
        }
        
       int prev2=1;
       int prev1=2;
       int curr=-1;
       for(int i=3;i<=n;i++){
       curr=prev2+prev1;
      prev2=prev1;
      prev1=curr;
       }
       return curr;
    }
    
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
       int ans=climbStairstabulation(n);
       return ans;
    }
};