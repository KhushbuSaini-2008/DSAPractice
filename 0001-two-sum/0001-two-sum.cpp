class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int first=nums[i];
                int second=nums[j];
                if(first+second==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};