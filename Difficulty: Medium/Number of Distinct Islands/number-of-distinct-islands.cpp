//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,vector<vector<int>>& grid,int ref_x,int ref_y,
       vector<vector<bool>>&visited,vector<pair<int,int>>&vec,int n,int m){
        
        visited[row][col]=true;
        vec.push_back({ref_x-row,ref_y-col});
        
        int delrow[]={0,0,-1,1};
        int delcol[]={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            
            if(newrow<n && newcol<m && newrow>=0 && newcol>=0 && grid[newrow][newcol]==1 
            && !visited[newrow][newcol]){
                
                dfs(newrow,newcol,grid,ref_x,ref_y,visited,vec,n,m);
            }
        }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                vector<pair<int,int>>vec;
                if( grid[i][j]==1 && !visited[i][j]){
                    
                    dfs(i,j,grid,i,j,visited,vec,n,m);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
        
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