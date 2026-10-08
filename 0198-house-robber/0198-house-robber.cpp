class Solution {
public:
// int solveusingrecursion(vector<int>&nums,int index){
    // int n=nums.size();
    // if(index>=n){
    //     return 0 ;
    // }
    // int include=nums[index]+solveusingrecursion(nums,index+2);
    // int exclude=0+solveusingrecursion(nums,index+1);
    // int ans=max(include,exclude);
    // return ans;
// }
// int solveusingrecursionmem(vector<int>&nums,int index,vector<int>dp){
//     int n=nums.size();
//     if(index>=n){
//         return 0;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int include=nums[index]+solveusingrecursionmem(nums,index+2,dp);
//     int exclude=0+solveusingrecursionmem(nums,index+1,dp);
//     int ans=max(include,exclude);
//     dp[n]=ans;
//     return ans;
// }
int solveusingtabulation(vector<int>&nums,int index){
    int n=nums.size();
    vector<int>dp(n+2,-1);
    dp[n]=0;
    dp[n+1]=0;
    for(int i=n-1;i>=0;i--){
    int include=nums[i]+dp[i+2];
    int exclude=0+dp[i+1];
    dp[i]=max(include,exclude);
   
    }
    return dp[index];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        int index=0;
        // int output=0;
        int ans=solveusingtabulation(nums,index);
        return ans;
        
    }
};