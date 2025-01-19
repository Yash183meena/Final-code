//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    void dfs(int node,vector<int>&component,vector<vector<int>>&graph,
    vector<bool>&visited){
        
        visited[node]=true;
        component.push_back(node);
        
        for(auto newnode:graph[node]){
            if(!visited[newnode]){
                dfs(newnode,component,graph,visited);
            }
        }
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>>graph(v+1);
        vector<vector<int>>components;
        vector<bool>visited(v+1,false);
        
        for(int i=0;i<e;i++){
             int x=edges[i][0];
             int y=edges[i][1];
            
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        int good=0;
        
        for(int i=1;i<=v;i++){
            vector<int>component;
            if(!visited[i]){
                dfs(i,component,graph,visited);
                components.push_back(component);
            }
        }
        
        for(auto component : components){
            
            int nodes=component.size()-1;
            bool flag=true;
            for(auto node : component){
                if(graph[node].size()!=nodes){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                good++;
            }
        }
        
        return good;
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends