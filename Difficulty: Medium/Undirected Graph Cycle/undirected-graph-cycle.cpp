//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int node,vector<vector<int>>& adj,map<int,int>&parent,vector<int>&visited){
        
        queue<int>que;
        que.push(node);
        
        visited[node]=true;
        
        while(!que.empty()){
            
            int node = que.front();
            que.pop();
            
            for(auto newnode : adj[node]){
                
                if(!visited[newnode]){
                    parent[newnode]=node;
                    que.push(newnode);
                    visited[newnode]=true;
                }
                
                else if(parent[node]!=newnode){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        int v=adj.size();
        map<int,int>parent;
        vector<int>visited(v,false);
        
        for(int i=0;i<v;i++){
            if(!visited[i] && isCyclic(i,adj,parent,visited)){
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