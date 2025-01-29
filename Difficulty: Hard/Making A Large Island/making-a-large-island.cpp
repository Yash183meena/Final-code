//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public: 
    int area=0;
    void findArea(vector<vector<int>>& grid,vector<vector<bool>>&visited,int row,int col,int id){
        
        visited[row][col]=true;
        grid[row][col]=id;
        area++;
        
        int delrow[]={0,0,-1,1};
        int delcol[]={1,-1,0,0};
        
        for(int i=0;i<4;i++){
            
            int newrow = row+delrow[i];
            int newcol = col+delcol[i];
            
            if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && 
            grid[newrow][newcol]==1 && !visited[newrow][newcol]){

                findArea(grid,visited,newrow,newcol,id);
            }
            
        }
        
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n=grid.size(),m=grid[0].size();
        map<int,int>areas;
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int id=2;
        int max_area=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    area = 0;
                    findArea(grid,visited,i,j,id);
                    areas[id]=area;
                    id++;
                    max_area=max(area,max_area);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    
                    map<int,bool>vis;
                area=0;
                    if(i-1>=0 && grid[i-1][j]!=0 && !vis[grid[i-1][j]]){
                        int id=grid[i-1][j];
                        vis[id]=true;
                        area+=areas[id];
                    }
                    
                    if(i+1<n && grid[i+1][j]!=0 && !vis[grid[i+1][j]]){
                        int id=grid[i+1][j];
                        vis[id]=true;
                        area+=areas[id];
                    }
                    
                    if(j-1>=0 && grid[i][j-1]!=0 && !vis[grid[i][j-1]]){
                        int id=grid[i][j-1];
                        vis[id]=true;
                        area+=areas[id];
                    }
                    
                    if(j+1<m && grid[i][j+1]!=0 && !vis[grid[i][j+1]]){
                        int id=grid[i][j+1];
                        vis[id]=true;
                        area+=areas[id];
                    }
                    
                    max_area=max(area+1,max_area);

                }
            }
        }
        
        return max_area;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends