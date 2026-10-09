class Solution {
public:
int solve(vector<int>&nums,int index,int ending){
   
   
    int next1=0;
    int next2=0;
    int curr=-1;

    for(int i=ending-1;i>=index;i--){
    int include=nums[i]+next2;
    int exclude=0+next1;
    curr=max(include,exclude);
    next2=next1;
    next1=curr;
   
    }
    return curr;
}
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        // vector<int>dp(n+1,-1);

        if(n==1){
            return nums[0];
        }
        int ans2=solve(nums,0,n-1);
        int ans1=solve(nums,1,n);
       int ans= max(ans2,ans1);
       
        return ans;

        
    }
};