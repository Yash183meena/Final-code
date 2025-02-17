//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     
     */
     
    int INT_MAX=1e8;
     
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        //Belman ford is different from the dijastra beacse it wors
        //from newgative edge cycle as well as it detct cycle
        
        vector<int>distance(V,INT_MAX);
        distance[src]=0;
        
        for(int i=0;i<V-1;i++){
            
            for(auto edge : edges){
                
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                
                if(distance[u]!=INT_MAX && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                }
            }
        }
        
        for(auto edge:edges){
            
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            if(distance[u]!=INT_MAX && distance[u] + wt < distance[v]){
                return {-1};
            } 
        }
        
        return distance;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends