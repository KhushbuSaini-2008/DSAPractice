class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0]; 
        }
      
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        int curr=max(nums[n-1],nums[n-2]);
        for(int i=2;i<n;i++){
            int ghar1=prev2+nums[i];
            int ghar2=prev1;
            curr=max(ghar1,ghar2);
            prev2=prev1;
            prev1=curr;
        }
return curr;
    }
};