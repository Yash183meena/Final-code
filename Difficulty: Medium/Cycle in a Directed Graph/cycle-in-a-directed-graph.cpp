//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int V, vector<vector<int>>&adj){
        
        queue<int>que;
        vector<int>indegre(V,0);
        
        for(int i=0;i<V;i++){
            
            for(auto node : adj[i]){
                indegre[node]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegre[i]==0){
                que.push(i);
            }
        }
        
        while(!que.empty()){
            
            int node=que.front();
            que.pop();
            
            for(auto newnode : adj[node]){
                
                indegre[newnode]--;
                
                if(indegre[newnode]==0){
                    que.push(newnode);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegre[i]>0){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        return check(V,adj);
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