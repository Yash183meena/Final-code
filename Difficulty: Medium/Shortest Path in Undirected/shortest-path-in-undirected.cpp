//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        int v=adj.size();
        queue<pair<int,int>>que;
        
        vector<int>distance(v,INT_MAX);
        que.push({0,src});
        
        distance[src]=0;
        
        while(!que.empty()){
            
            int wt=que.front().first;
            int x=que.front().second;
            que.pop();
            
            for(auto newnode:adj[x]){
                
                if(distance[newnode] > wt + 1){
                    distance[newnode] = distance[x] + 1;
                    que.push({distance[newnode],newnode});
                }
            }
        }
        
        for(int i=0;i<v;i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        
        return distance;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends