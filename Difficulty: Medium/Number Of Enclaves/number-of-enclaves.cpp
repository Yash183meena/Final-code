//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>que;

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                que.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][m-1]==1){
                que.push({i,m-1});
                grid[i][m-1]=0;
            }
        }

        for(int i=1;i<m-1;i++){
            if(grid[0][i]==1){
                que.push({0,i});
                grid[0][i]=0;
            }
            if(grid[n-1][i]==1){
                que.push({n-1,i});
                grid[n-1][i]=0;
            }
        }

        while(!que.empty()){

            int x=que.front().first;
            int y=que.front().second;
            que.pop();

            int delrow[]={1,-1,0,0};
            int delcol[]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int newrow=delrow[i]+x;
                int newcol=delcol[i]+y;

                if(newrow<n && newcol<m && newrow>=0 && newcol>=0 && grid[newrow][newcol]==1){
                    que.push({newrow,newcol});
                    grid[newrow][newcol]=0;
                }
            }
        }

        int ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              
                if(grid[i][j]==1){
                    ones++;
                }
                
            }
        }

        return ones;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends