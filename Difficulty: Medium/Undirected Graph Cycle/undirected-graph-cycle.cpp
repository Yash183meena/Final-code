//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int node,vector<vector<int>>& adj,vector<int>&visited,int parent){
        
        
        visited[node]=true;
        
        for(auto newnode : adj[node]){
            
            if(visited[newnode]){
                
                if(newnode == parent){
                    continue;
                }
                
                else{
                    return true;
                }
        }
        
        else if(isCyclic(newnode,adj,visited,node)){
            return true;
        }
        
    }
    
    return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isCyclic(i,adj,visited,-1)){
                return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends