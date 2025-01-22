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
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<>>pq;
        
        vector<vector<bool>>visited(N,vector<bool>(M,false));
        
        pq.push({0,{0,0}});
        visited[0][0]=true;
        
        if(A[0][0]==0){
            return -1;
        }
        
        while(!pq.empty()){
            
            int steps = pq.top().first;
            
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            
            if(x==X && y==Y){
                return steps;
            }
            
            int delrow[]={-1,1,0,0};
            int delcol[]={0,0,-1,1};
            
            for(int i=0;i<4;i++){
                
                int newrow = delrow[i] + x;
                int newcol = delcol[i] + y;
                
                if(newrow<N && newrow>=0 && newcol<M && newcol>=0 && 
                !visited[newrow][newcol] && A[newrow][newcol]==1){
                    visited[newrow][newcol]=true;
                    pq.push({steps+1,{newrow,newcol}});
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
// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg