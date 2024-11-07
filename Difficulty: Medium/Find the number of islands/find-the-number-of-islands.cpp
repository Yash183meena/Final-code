//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid,int row,int col,int n,int m,vector<vector<bool>>& visited){
        
        visited[row][col]=true;
        
        int delrow[]={1, -1, 0, 0, 1, -1, 1, -1};
        int delcol[]={0, 0, -1, 1, 1, -1, -1, 1};
        
        for(int i=0;i<8;i++){
            
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            
            if(newrow<n && newcol<m && newrow>=0 && newcol>=0 && !visited[newrow][newcol] 
                  && grid[newrow][newcol]=='1'){
                
                dfs(grid,newrow,newcol,n,m,visited);
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int islands=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1' && !visited[i][j]){
                    
                    dfs(grid,i,j,n,m,visited);
                    islands++;
                    
                }
            }
        }
        
        return islands;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends