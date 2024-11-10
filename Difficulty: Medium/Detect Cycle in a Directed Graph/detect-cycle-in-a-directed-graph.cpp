//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<vector<int>>&graph,vector<int>&safe,vector<bool>&visited,int node,vector<bool>&pathVisited){
        
        pathVisited[node]=true;
        visited[node]=true;
        safe[node]=0;
        
        for(auto newnode : graph[node]){
            if(!visited[newnode]){
                if(dfs(graph,safe,visited,newnode,pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[newnode]){
                return true;
            }
        }
        
        pathVisited[node]=0;
        safe[node]=1;
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int>safe(V,1),ans;
        vector<bool>visited(V,false),pathVisited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,safe,visited,i,pathVisited)){
                    return true;
                }
            }
        }
        
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends