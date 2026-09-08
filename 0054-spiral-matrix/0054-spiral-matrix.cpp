class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int startingrow=0;
        int endingrow=n-1;
        int startingcol=0;
        int endingcol=m-1;
        vector<int>temp;
        while(startingrow<=endingrow && startingcol<=endingcol){
            if(startingrow<=endingrow){
                for(int i=startingcol;i<=endingcol;i++){
               temp.push_back(matrix[startingrow][i]);
                }
                startingrow++;
            }
            if(startingcol<=endingcol){
                for(int i=startingrow;i<=endingrow;i++){
               temp.push_back(matrix[i][endingcol]);
                }
                endingcol--;
            }
            if(startingrow<=endingrow){
                for(int i=endingcol;i>=startingcol;i--){
               temp.push_back(matrix[endingrow][i]);
                }
                endingrow--;
            }
            if(startingcol<=endingcol){
                for(int i=endingrow;i>=startingrow;i--){
               temp.push_back(matrix[i][startingcol]);
                }
                startingcol++;
            }
        }
        return temp;
    }
};