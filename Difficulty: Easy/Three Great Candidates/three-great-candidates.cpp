//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        
        int d=INT_MAX,e=INT_MAX;
        
        for(int i=0;i<arr.size();i++){
            
            if( arr[i] > a ){
                c=b;
                b=a;
                a=arr[i];
            }
            
            else if( arr[i] > b ){
                c=b;
                b=arr[i];
            }
            
            else if( arr[i] > c ){
                c=arr[i];
            }
            
            if( arr[i] < d ){
                e=d;
                d=arr[i];
            }
            
            else if( arr[i] <e ){
                e=arr[i];
            }
        }
        
        
        return max(a*b*c,a*d*e);
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends