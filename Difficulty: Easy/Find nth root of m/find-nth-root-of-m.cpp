//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        
        int low=0,high=m;
        int mid;
        
        while(low <= high){
            
            int r=1;
            
            mid = low + (high - low)/2;
            
            for(int i=0;i<n;i++){
                r*=mid;
            }
            
            if(r == m){
                return mid;
            }
            
            else if(r < m){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends