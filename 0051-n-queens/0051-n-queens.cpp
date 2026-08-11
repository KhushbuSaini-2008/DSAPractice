class Solution {
public:
unordered_map<int,bool>lefthorizonatal;
unordered_map<int,bool>upperdiagonal;
unordered_map<int,bool>lowerdiagonal;

// void storeanswer(vector<vector<char>>&board,vector<vector<string>>&ans,int n){
//     vector<string>temp;
//     for(int i=0;i<n;i++){
//         string output="";
//         for(int j=0;j<n;j++){
//             char ch=board[i][j];
//             output.push_back(ch);
//         }
//         temp.push_back(output);

//     }
//     ans.push_back(temp);
// }
bool issafe(vector<string>&board,vector<vector<string>>&ans,int row,int col){
    // //we have too checkonly in8 direction
    // //left side
    // int n=board.size();
    // for(int i=0;i<col;i++){
    //     if(board[row][i]=='Q'){
    //         return false;
    //     }
    // }
    // //left diaginal
    // int i=row-1;
    // int j=col-1;
    // while(i>=0 && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }
    // //right diaginal
    // int x=row+1;
    // int y=col-1;
    // while(x<n && y>=0){
    //     if(board[x][y]=='Q'){
    //         return false;
    //     }
    //     x++;
    //     y--;
    // }
    // return true;
    if( lefthorizonatal[row]==true){
        return false;

    }
    if( upperdiagonal[row-col]==true){
        return false;

    }
    if(lowerdiagonal[row+col]==true){
        return false;

    }
    return true;
}
void solve(vector<string>&board,vector<vector<string>>&ans,int col,int n){
    if(col>=n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
    if(issafe(board,ans,row,col)){
        lefthorizonatal[row]=true;
        upperdiagonal[row-col]=true;
        lowerdiagonal[row+col]=true;
        board[row][col]='Q';
        solve(board,ans,col+1,n);
        board[row][col]='.';
         lefthorizonatal[row]=false;
        upperdiagonal[row-col]=false;
        lowerdiagonal[row+col]=false;
    }
}
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        int col=0;
        solve(board,ans,col,n);
        return ans;
        
    }
};
// class Solution {
// public:
// void storeanswer(vector<vector<char>>&board,vector<vector<string>>&ans,int n){
//     vector<string>temp;
//     for(int i=0;i<n;i++){
//         string output="";
//         for(int j=0;j<n;j++){
//             char ch=board[i][j];
//             output.push_back(ch);
//         }
//         temp.push_back(output);

//     }
//     ans.push_back(temp);
// }
// bool issafe(vector<vector<char>>&board,vector<vector<string>>&ans,int row,int col){
//     //we have too checkonly in8 direction
//     //left side
//     int n=board.size();
//     for(int i=0;i<col;i++){
//         if(board[row][i]=='Q'){
//             return false;
//         }
//     }
//     //left diaginal
//     int i=row-1;
//     int j=col-1;
//     for(;(i>=0 && j>=0) ;(i-- && j--)){
//         if(board[i][j]=='Q'){
//             return false;
//         }
//     }
//     //right diaginal
//     int x=row+1;
//     int y=col-1;
//     for(;(x<n && j>=0) ;(i++ && j--)){
//         if(board[x][y]=='Q'){
//             return false;
//         }
//     }
//     return true;
// }
// void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
//     if(col>=n){
//         storeanswer(board,ans,n);
//         return;
//     }
//     for(int row=0;row<n;row++){
//     if(issafe(board,ans,row,col)){
//         board[row][col]='Q';
//         solve(board,ans,col+1,n);
//         board[row][col]='.';
//     }
// }
// }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<vector<char>>board(n,vector<char>(n,'.'));
//         int col=0;
//         solve(board,ans,col,n);
//         return ans;
        
//     }
// };
