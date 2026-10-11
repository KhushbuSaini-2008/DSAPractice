class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int index=1;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
            sum=sum+nums[i]*nums[i];

            }
            else{
                continue;
            }
        }
        return sum;
    }
};