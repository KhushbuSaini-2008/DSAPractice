class Solution {
public:

// int solveWithmem(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
   
//     if(curr>=nums.size()){
//         return 0;
//     }
//     if(dp[curr][prev+1]!=-1){
//         return dp[curr][prev+1];
//     }
// int include=0;
// if(prev==-1 || nums[curr]>nums[prev]){
//    include=1+solveWithmem(nums,curr+1,curr,dp);
// }
//     int exclude=0+solveWithmem(nums,curr+1,prev,dp);
//     int final=max(include,exclude);
//     dp[curr][prev+1]=final;
//     return final;

// }
int solveusingtab(vector<int>&nums,int curr,int prev){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
    int include=0;
if(prev==-1 || nums[curr]>nums[prev]){
   include=1+dp[curr+1][curr+1];
}
    int exclude=0+dp[curr+1][prev+1];
    int final=max(include,exclude);
    dp[curr][prev+1]=final;

        }
    }
    return dp[0][0];
}
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        //2d dp
        //create pass send receive initialze

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveusingtab(nums,curr,prev);
        return ans;
        
    }
};