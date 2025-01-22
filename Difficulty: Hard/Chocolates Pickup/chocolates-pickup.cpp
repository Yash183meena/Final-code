//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[71][71][71];
    
    int solveMem(int row,int col1,int col2,int n,int m, vector<vector<int>>& grid){
        
        if(row>=n || row<0 || col1<0 || col2<0 || col1>=m || col2>=m ){
            return 0;
        }
        
        if(dp[row][col1][col2]!=-1){
            return dp[row][col1][col2];
        }
        
        int cherry=0;
        int moves[]={-1,0,1};
        
        for(int newcol1=0;newcol1<3;newcol1++){
            
            for(int newcol2=0;newcol2<3;newcol2++){
                
                if(col1 == col2){
                    
                    cherry = max(cherry, grid[row][col1] + 
                    solveMem(row+1,col1+moves[newcol1],col2 +moves[newcol2],n,m,grid) );
                }
                
                else{
                    cherry = max(cherry, grid[row][col1] + grid[row][col2] +
                    solveMem(row+1,col1+moves[newcol1],col2+moves[newcol2],n,m,grid) );
                }
            }
        }
        
        return dp[row][col1][col2]=cherry;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        memset(dp,-1,sizeof(dp));
        return solveMem(0,0,m-1,n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends