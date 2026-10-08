class Solution {
public:
    string removeOuterParentheses(string s) {
        int d=0;
        string result;
        for(int i:s){
        if(i=='('){
           
            if(d!=0){
                result.push_back(i);
                d++;
            }
            else{
                d++;
            }

        }
        else{
            d--;
            if(d!=0){
                result.push_back(i);
            }
        }
        }
return result;
    }
};