class Solution {
public:
int solveusingRec(vector<int>&nums,int curr,int prev){
    //base case
    if(curr>=nums.size()){
        return 0;
    }
    int include=0;
    if(prev==-1 || nums[curr]>nums[prev]){
     include=1+solveusingRec(nums,curr+1,curr);
    }
    int exclude=0+solveusingRec(nums,curr+1,prev);
    int final=max(include,exclude);
    return final;
}
//solveusing mem
//analyze dp type and create initilze pass receive recursivecall
//store value and checkvalue
int solveusingmem(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=nums.size()){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    int include=0;
    if(prev==-1 || nums[curr]>nums[prev]){
     include=1+solveusingmem(nums,curr+1,curr,dp);
    }
    int exclude=0+solveusingmem(nums,curr+1,prev,dp);
    int final=max(include,exclude);
    dp[curr][prev+1]=final;
    return final;

}
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        //2d dp
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveusingmem(nums,curr,prev,dp);
        return ans;
        
    }
};