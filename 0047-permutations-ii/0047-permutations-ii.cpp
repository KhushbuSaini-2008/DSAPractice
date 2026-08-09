class Solution {
public:
void solve(vector<int>& nums,int i,vector<vector<int>>&output){
    
    if(i>=nums.size()){
        output.push_back(nums);
        return;
    }
    set<int>used;
    int j=0;
    for( j=i;j<nums.size();j++){
        if(used.count(nums[j])) 
                continue;
            

        used.insert(nums[j]);

        swap(nums[i],nums[j]);
        solve(nums,i+1,output);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i=0;
        vector<int>output;
       vector<vector<int>>ans;
       solve(nums,i,ans);
       sort(ans.begin(),ans.end());
       return ans;
    }
};