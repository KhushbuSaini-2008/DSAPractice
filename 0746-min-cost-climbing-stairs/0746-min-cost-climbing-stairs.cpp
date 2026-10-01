class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       
       int prev2=0;
       int prev1=0;
       int curr=-1;
        for(int i=2;i<=n;i++){
            int a=prev2;
            int b=prev1;
           curr=min(a+cost[i-2],b+cost[i-1]);
           prev2=prev1;
           prev1=curr;
        }
        return curr;
        
    }
};