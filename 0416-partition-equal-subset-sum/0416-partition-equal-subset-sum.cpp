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
bool solveTbso(vector<int>&nums,int index,int target){
    int n=nums.size();
    // vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    vector<int>curr(target+1,0);
    vector<int>next(target+1,0);
    for(int i=0;i<n;i++){
    curr[0]=1;
    }
    curr[target]=0;
    for(int i=n-1;i>=0;i--){
        for(int t=1;t<=target;t++){
    bool ans=false;
    bool include=false;
    if(t-nums[i]>=0){
    include=next[t-nums[i]];
    }
    bool exclude=next[t];
    
   curr[t]=(include||exclude);
 
  

        }
        next=curr;
    }
    return curr[target];
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
        bool ans=solveTbso(nums,index,target);
        return ans;
        
    }
};