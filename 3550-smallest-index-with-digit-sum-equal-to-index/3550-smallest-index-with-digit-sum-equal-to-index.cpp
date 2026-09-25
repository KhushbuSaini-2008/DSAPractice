class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int digit=0;
            int sum=0;
            while(nums[i]>0){
             digit=nums[i]%10;
             sum=sum+digit;
            nums[i]=nums[i]/10;
            }
            if(sum==i){
                return i;
            }
            
        }
        return -1;
    }
};