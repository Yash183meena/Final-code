//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        map<int,int>rank;
        priority_queue<int,vector<int>,greater<>>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        int rak=1;
        
        while(!pq.empty()){
            
            int element = pq.top();
            pq.pop();
            
            if(rank.find(element)==rank.end()){
                rank[element]=rak;
                rak++;
            }
        }
        
        for(int i=0;i<arr.size();i++){
              
            int r = rank[arr[i]];
            arr[i]=r;
        }
        
        return arr;
    }

};



//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends