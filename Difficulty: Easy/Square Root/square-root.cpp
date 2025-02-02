//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low=0,high=n;
        
        while(low <= high){
            
            int mid = low+(high-low)/2;
            
            if(mid*mid == n){
                return mid;
            }
            
            else if( mid*mid > n){
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        
        return low-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends