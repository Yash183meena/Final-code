//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int max(int a,int b){
        return a>b;
    }
    
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        long long product=1;
        int ans=INT_MIN;
        for(auto ele:arr){
            product*=ele;

            if(product>ans){
                ans=product;
            }
            if(product==0){
                product=1;
            }
        }
        product=1;
        reverse(begin(arr),end(arr));
        for(auto ele:arr){
            product*=ele;
            if(product>ans){
                ans=product;
            }
            if(product==0){
                product=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends