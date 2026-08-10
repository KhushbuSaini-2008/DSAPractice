class Solution {
public:
vector<vector<int>>solve(vector<int>&nums, int i,vector<vector<int>>&ans){
    
    if(i>=nums.size()){
        ans.push_back(nums);
        return ans;
    }
    
    for(int j=i;j<nums.size();j++ ){
        swap(nums[i],nums[j]);
        solve(nums,i+1,ans);
        swap(nums[i],nums[j]);
        
    }
    return ans;

}
    vector<vector<int>> permute(vector<int>& nums) {
        int index=0;
        vector<vector<int>>ans;
        solve(nums,index,ans);
        return ans;
       
    }
};