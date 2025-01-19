//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{0,0}});
        
        
        vector<vector<bool>>visited(N,vector<bool>(M,false));
        visited[0][0]=true;
        
        if(A[0][0]==0){
            return -1;
        }
        
        while(!pq.empty()){
            
            int cost=pq.top().first;
            
            int x = pq.top().second.first;
            int y=pq.top().second.second;
            
            pq.pop();
            
            if(x==X && y==Y){
                return cost;
            }
            
            int delrow[]={0,0,1,-1};
            int delcol[]={1,-1,0,0};
            
            for(int i=0;i<4;i++){
                
                int newrow = x+delrow[i];
                int newcol= y+delcol[i];
                
                if(newrow<N && newcol<M && newrow>=0 && newcol>=0 && !visited[newrow][newcol] &&
                 A[newrow][newcol] == 1){
                    
                    visited[newrow][newcol] = true;
                    pq.push({cost+1,{newrow,newcol}});
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends