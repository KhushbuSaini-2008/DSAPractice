class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int sum=0;
        int result=INT_MAX;
        
        int n=nums.size();
       int end=accumulate(nums.begin(),nums.end(),0);
       if(end<target){
        return 0;
       }
      
        while(high<n){
            sum+=nums[high];
            
            while(sum>=target){
            int length=high-low+1;
             result=min(result,length);
                sum=sum-nums[low];
                low++;


            }
            high++;
           
        }
        return result;
    }
};