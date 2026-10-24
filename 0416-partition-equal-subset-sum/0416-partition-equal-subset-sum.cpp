class Solution {
public:
bool solve(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
    if(target<0 )
    return false;
    if( index>=nums.size()){
        return false;
    }
    if(target==0){
        return true;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool ans=false;
    bool include=solve(nums,index+1,target-nums[index],dp);
    bool exclude=solve(nums,index+1,target,dp);
    
    ans= (include||exclude);
 
   dp[index][target]=ans;
   return ans;
}
bool solveTb(vector<int>&nums,int index,int target){
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    dp[index][0]=1;
    for(int i=0;i<=n;i++){
        for(int t=0;t<=target;t--){
    bool ans=false;
    bool include=dp[i+1][t-nums[i]];
    bool exclude=dp[i+1][t];
    
    ans= (include||exclude);
 
   dp[i][t]=ans;

        }
    }
    return dp[0][target];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        int target=sum>>1;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int index=0;
        bool ans=solve(nums,index,target,dp);
        return ans;
        
    }
};