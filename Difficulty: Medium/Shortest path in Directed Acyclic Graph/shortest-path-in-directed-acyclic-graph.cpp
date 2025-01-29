//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   void dfs(int node,map<int,vector<pair<int,int>>>&graph,vector<int>&visited,
   stack<int>&stk){
       
       visited[node]=true;
       
       for(auto newnode_pair : graph[node]){
           
           int newnode = newnode_pair.first;
           
           if(!visited[newnode]){
               dfs(newnode,graph,visited,stk);
           }
       }
       
       stk.push(node);
   }
   
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        map<int,vector<pair<int,int>>>graph;
        vector<int>distance(V,INT_MAX);
        stack<int>stk;
        vector<int>visited(V,false);
        
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            
            graph[from].push_back({to,weight});
        }
        
        //loop beacuse if there is more than one componenet in graph
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(0,graph,visited,stk);
            }
        }
        
        distance[0]=0;
        
        while(!stk.empty()){
            
            int node = stk.top();
            stk.pop();
            
            for(auto newnode_pair : graph[node]){
                
                int newnode = newnode_pair.first;
                int weight = newnode_pair.second;
                
                if( distance[newnode] > distance[node] + weight ){
                    
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