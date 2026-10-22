class Solution {
public:
// int recursionsolution(vector<int>& coins, int amount){
//     if(amount==0){
//         return 0;
//     }
//     int ans=INT_MAX;
//     for(int i=0;i<coins.size();i++){
//         if(coins[i]<=amount){
//         int reans=recursionsolution(coins,amount-coins[i]);
//         if(reans!=INT_MAX){
//         ans=min(ans,1+reans);
//         }
//         }
        
//     }
// return ans;
// }
int recursionsolutionmem(vector<int>& coins, int amount,vector<int>&dp){
    if(amount==0){
        return 0;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(coins[i]<=amount){
        int reans=recursionsolutionmem(coins,amount-coins[i],dp);
        if(reans!=INT_MAX){
        ans=min(ans,1+reans);
        }
        }
        dp[amount]=ans;
        
    }
return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=amount;
        vector<int>dp(n+1,-1);

       int ans=INT_MAX;
       ans=recursionsolutionmem(coins,amount,dp);
       if(ans==INT_MAX){
        return -1;
       }
       else{
        return ans;
       }
        
    }
};