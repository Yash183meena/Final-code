//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        
        int low = 0,high=m;
        
        while( low<= high){
            
            int mid = low + (high - low)/2;
            
            int p=1;
            for(int i=1;i<=n;i++){
                p*=mid;
            }
            
            if(p == m){
                return  mid;
            }
            
            else if( p < m){
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