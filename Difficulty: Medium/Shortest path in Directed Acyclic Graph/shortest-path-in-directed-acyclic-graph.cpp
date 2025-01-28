//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int node,map<int,vector<pair<int,int>>>&graph,stack<int>&topo, vector<int>&visited){
        
        visited[node]=true;
        
        for(auto newnode_pair : graph[node]){
            
            int newnode=newnode_pair.first;
            
            if(!visited[newnode]){
                topoSort(newnode,graph,topo,visited);
            }
        }
        
        topo.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
    
        map<int,vector<pair<int,int>>>graph;
        
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            
            graph[from].push_back({to,weight});
        }
        
        vector<int>visited(V,false);
        vector<int>distance(V,INT_MAX);
        stack<int>topo;
        
        //if there are more than one componenets
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(0,graph,topo,visited);
            }
        }
        
        distance[0]=0;
        
        while(!topo.empty()){
            
            int node = topo.top();
            topo.pop();
            
            for(auto newnode_pair : graph[node]){
                
                int newnode = newnode_pair.first;
                int weight = newnode_pair.second;
                
                if(distance[newnode] > distance[node] + weight){
                    distance[newnode] = distance[node] + weight;
                }
            }
        }
        
        for(int i=0;i<V;i++){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends