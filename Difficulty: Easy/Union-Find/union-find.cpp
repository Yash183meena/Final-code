//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    int find(int node,int par[]){
        
        if(node == par[node]){
            return node;
        }
        
        return find(par[node],par);
    }
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        int parent_x = find(a,par);
        int parent_y = find(b,par);
        
        if(parent_x == parent_y){
            return;
        }
        
        else if(rank1[parent_x] > rank1[parent_y]){
            par[parent_y]=parent_x;
        }
        
        else if(rank1[parent_x] < rank1[parent_y]){
            par[parent_x]=parent_y;
        }
        
        else{
            par[parent_y] = parent_x;
            rank1[parent_x]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank11[])
    {
        //code here
        
        int parent_x = find(x,par);
        int parent_y = find(y,par);
        
        if( parent_x == parent_y ){
            return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank11[n+1];

        //initializing the parent and
        //the rank1 array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank11[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank11);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank11)<<endl;
    }
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends