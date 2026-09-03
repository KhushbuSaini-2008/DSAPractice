class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans=0;
        for(int i:s){
          char ch=i; 
            if(ch=='('){
ans++;
st.push(ch);
            }
            else{
if(!st.empty()){
    st.pop();
    ans--;
}
else{
    ans++;
}
            }

                    }
                    return ans;
    }
};