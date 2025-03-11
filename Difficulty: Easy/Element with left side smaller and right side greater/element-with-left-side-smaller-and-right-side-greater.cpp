//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int left_max=INT_MIN,right_min=INT_MAX;
        vector<int>left(n);
        vector<int>right(n);
        
        for(int i=n-1;i>=0;i--){
            
            if(arr[i] < right_min){
                right[i]=-1;
                right_min=arr[i];
            }
            else{
                right[i]=right_min;
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(arr[i] > left_max){
                left[i]=-1;
                left_max=arr[i];
            }
            else{
                left[i]=left_max;
            }
        }
        
        for(int i=1;i<n-1;i++){
            if(left[i] ==-1 && right[i]==-1){
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