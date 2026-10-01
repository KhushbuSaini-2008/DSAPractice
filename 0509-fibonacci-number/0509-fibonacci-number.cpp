class Solution {
public:
int fibmemo(int n){
    if(n==0){
        return n;
    }
        vector<int>dp(n+1,-1);
        
       dp[0]=0;
       dp[1]=1;
     
        for(int i=2;i<=n;i++){
     int ans=dp[i-1]+dp[i-2];
        dp[i]=ans;
        }
        return dp[n];
}
int fibomemoso(int n){
       if(n==0||n==1){
        return n;
    }
        
       int prev2=0;
       int prev1=1;
       int curr=-1;
     
        for(int i=2;i<=n;i++){
    curr=prev1+prev2;
       prev2=prev1;
       prev1=curr;
        }
        return curr;
}


    int fib(int n) {
        // if(n==0|| n==1){
        //     return n;
        // }
        // int ans=fib(n-1)+fib(n-2);
        // r
        int ans=fibomemoso(n);
        return ans;
    }
};