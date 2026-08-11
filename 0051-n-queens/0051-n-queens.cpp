class Solution {
public:
void storeanswer(vector<vector<char>>&board,vector<vector<string>>&ans,int n){
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
bool issafe(vector<vector<char>>&board,vector<vector<string>>&ans,int row,int col){
    //we have too checkonly in8 direction
    //left side
    int n=board.size();
    for(int i=0;i<col;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    //left diaginal
    int i=row-1;
    int j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    //right diaginal
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
void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
    if(col>=n){
        storeanswer(board,ans,n);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col=0;
        solve(board,ans,col,n);
        return ans;
        
    }
};