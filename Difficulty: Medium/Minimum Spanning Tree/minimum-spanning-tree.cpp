//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int mst=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        
        vector<bool>visited(V,false);
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            int wt=pq.top().first;
            
            pq.pop();
            
            if(visited[node]){
                continue;
            }
            
            visited[node]=true;
            mst+=wt;
            
            for(auto newnode_pair : adj[node]){
                
                int newnode = newnode_pair[0];
                int weight = newnode_pair[1];
                
                if(visited[newnode]){
                    continue;
                }
                
                else{
                    pq.push({weight,newnode});
                }
            }
        }
        
        return mst;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends