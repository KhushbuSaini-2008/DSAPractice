class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double low=0;
        double high=k-1;
        double avg=0;
        double result=INT_MIN;
        for(int i=low;i<=high;i++){
            sum+=nums[i];
        }
            avg=sum/k;
            int n=nums.size();
            while(high<n){
                result=max(result,avg);
                sum=sum-nums[low];
                low++;
                high++;
                if(high==n){
                    break;
                }
                sum=sum+nums[high];
                avg=sum/k;

            }
return result;
    }
};