//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        map<int,vector<pair<int,int>>>graph;
        
        for(int i=0;i<V;i++){
            
            for(auto edge : adj[i]){
                
                int x=edge[0];
                int wt=edge[1];
                
                graph[i].push_back({x,wt});
            }
        }
        
        vector<bool>visited(V,false);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        int mst=0;
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            int wt=pq.top().first;
            
            pq.pop();
            
            
            if(visited[node]){
                continue;
            }
            
            mst+=wt;
            visited[node]=true;
            
            for(auto newnode_pair : graph[node]){
                
                int newnode=newnode_pair.first;
                int cost=newnode_pair.second;
                
                if(visited[newnode]){
                    continue;
                }
                
                else{
                    
                    pq.push({cost,newnode});
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