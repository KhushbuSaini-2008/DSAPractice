class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            int a=dp[i-2];
            int b=dp[i-1];
            dp[i]=min(a+cost[i-2],b+cost[i-1]);
        }
        return dp[n];
        
    }
};