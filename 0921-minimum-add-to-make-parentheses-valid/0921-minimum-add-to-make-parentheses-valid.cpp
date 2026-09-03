class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char>st;
       int count=0;
       st.push(-1);
       for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('){
        st.push(ch);
        }
        else{
           if(ch==')' && st.top()=='(' ){
            st.pop();
        }
       else if(ch==')'&& st.top()==-1){
            count++;
           
        }
       }
       }
     
         while(!st.empty() && st.top()=='('){

            count++;
            st.pop();
           }
       return count;
    }
};