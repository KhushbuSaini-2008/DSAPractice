class Solution {
public:
void storesolution(vector<vector<char>> &board,vector<vector<string>>&ans,int n){
    vector<string>temp;
    for(int i=0;i<n;i++){
        string output="";
        for(int j=0;j<n;j++){
            char ch=board[i][j];
            output.push_back(ch);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

bool issafe(int row,int col,vector<vector<char>>&board){
    int n =board.size();
    for(int i=0;i<col;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    int i=row-1;
    int j=col-1;
    while(j>=0 && i>=0){
       if(board[i][j]=='Q'){
        return false;
       }
        i--;
        j--;
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
void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int n,int col){
    
    if(col>=n){
        storesolution(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board)){
            board[row][col]='Q';
        
        solve(board,ans,n,col+1);
        board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col=0;
        solve(board,ans,n,col);
        return ans;
    }
};