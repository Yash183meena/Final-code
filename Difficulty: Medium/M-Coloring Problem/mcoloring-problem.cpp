//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSafe(int node,int v,vector<int>&color,vector<vector<int>>&graph,int colour){
        
        for(int i=0;i<v;i++){
            
            if( node!=i && graph[node][i] && color[i] == colour){
                return false;
            }
        }
        
        return true;
    }
    
    bool fillColor(int node,vector<vector<int>>&graph,vector<bool>&visited,
         vector<int>&color,int v,int m){
             
        if(node == v){
            return true;
        }
             
        for(int i=1;i<=m;i++){
            
            if(isSafe(node,v,color,graph,i)){
                
                color[node] = i;
                
                if(fillColor(node+1,graph,visited,color,v,m)){
                    return true;
                }
                
                //Backtracking
                else{
                    color[node] = -1;
                }
            }
            
        }
        
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>>graph(v,vector<int>(v,0));
        
        for(int i=0;i<edges.size();i++){
            int x = edges[i].first;
            int y = edges[i].second;
            
            graph[x][y]=1;
            graph[y][x]=1;
        }
        
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<int>color(n,-1);
        
        return fillColor(0,graph,visited,color,v,m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends