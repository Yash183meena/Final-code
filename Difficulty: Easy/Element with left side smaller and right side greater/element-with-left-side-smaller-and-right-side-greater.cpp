//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        // Code here
        int min=INT_MAX,max=INT_MIN,n=arr.size();
        vector<int>greater(n),smaller(n);
    
        for(int i=0;i<n;i++){
            if(max<arr[i]){
                max=arr[i];
                greater[i]=-1;
            }
            else{
                greater[i]=max;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(arr[i] < min){
                smaller[i]=-1;
                min=arr[i];
            }
            else{
                smaller[i]=min;
            }
        }
        
        
        for(int i=1;i<n-1;i++){
            if(smaller[i]==-1 && greater[i]==-1){
                return arr[i];
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.findElement(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends