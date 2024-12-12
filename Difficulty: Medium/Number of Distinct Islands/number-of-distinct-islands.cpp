//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>&visited,
    vector<pair<int,int>>&island,int base_row,int base_col,int n,int m){
        
        
        visited[row][col]=true;
        
        int delrow[]={1,-1,0,0};
        int delcol[]={0,0,1,-1};
        
        island.push_back({row-base_row,col-base_col});
        
        for(int i=0;i<4;i++){
            
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            
            if(newcol<m && newrow<n && newrow>=0 && newcol>=0 && !visited[newrow][newcol] 
            && grid[newrow][newcol]==1){
                dfs(grid,newrow,newcol,visited,island,base_row,base_col,n,m);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<pair<int,int>>island;
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid,i,j,visited,island,i,j,n,m);
                    st.insert(island);
                    island.clear();
                }
            }
        }
        
        int distint=st.size();
        return distint;

    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends