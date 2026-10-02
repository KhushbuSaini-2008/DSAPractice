class Solution {
public:
void solve(int n,int open,int close,string &part,vector<string>&ans){
 if(part.length()==2*n){
    ans.push_back(part);
    return;
 }
 if(open<n){
    part.push_back('(');
    solve(n,open+1,close,part,ans);
    part.pop_back();
 }
if(open>close){
    part.push_back(')');
    solve(n,open,close+1,part,ans);
    part.pop_back();
}



}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
           string part="";
    solve(n,0,0,part,ans);
    return ans;
    }
};