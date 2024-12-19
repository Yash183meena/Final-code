//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int mod = 1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<vector<pair<int,int>>>graph(n);
        
        for(int i=0;i<roads.size();i++){
            
            int x=roads[i][0];
            int y=roads[i][1];
            int t=roads[i][2];
            
            graph[x].push_back({y,t});
            graph[y].push_back({x,t});
        }
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<int>ways(n,0);
        vector<long long>dis(n,LONG_MAX);
        
        pq.push({0,0});
        
        dis[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            
            long long tim = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto node_pair : graph[node]){
                
                int newnode = node_pair.first;
                long long t = node_pair.second;
                
                if( dis[newnode] > tim + t ){
                    dis[newnode] = tim + t;
                    pq.push({dis[newnode],newnode});
                    ways[newnode] = ways[node]%mod;
                }
                
                else if(dis[newnode] == tim + t){
                    ways[newnode] = (ways[node]%mod + ways[newnode]%mod)%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends