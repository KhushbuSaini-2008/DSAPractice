#include<string.h>
class Solution {
public:
bool issafe(vector<string>&board,int &ans,int row,int col){
    int n=board.size();
    for(int i=0;i<col;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    int i=row-1;
    int j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--,j--;
    }
    int x=row+1;
    int y=col-1;
    while(x<n && y>=0){
         if(board[x][y]=='Q'){
            return false;
        }
        x++;
        y--;

    }
    return true;
}
void solve(vector<string>&board,int &ans,int col,int n){
    if(col>=n){
       ans++;
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(board,ans,row,col)){
            board[row][col]='Q';
            solve(board,ans,col+1,n);
            board[row][col]='.';
        }
    }
}
    int totalNQueens(int n) {
    vector<string>board(n,string(n,'.'));
    int ans=0;
    int col=0;
    solve(board,ans,col,n);
    return ans;

    }
};