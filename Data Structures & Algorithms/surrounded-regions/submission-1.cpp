class Solution {
public:
int m,n;
void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<char>>& board){
    vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
    vis[r][c]=true;

    for(auto &d:dir){
        int nr=r+d[0];
        int nc=c+d[1];

        if(nr<0||nc<0||nr>m-1||nc>n-1)
        continue;

        if(vis[nr][nc]==true)
        continue;

        if(board[nr][nc]=='X')
        continue;

        dfs(nr,nc,vis,board);
    }



}
public:
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
        dfs(0,j,vis,board);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
        dfs(i,0,vis,board);
        }
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O')
        dfs(m-1,j,vis,board);
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O')
        dfs(i,n-1,vis,board); 
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==true)
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }

     
    }
};