//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        int len=1;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                len++;
            }
        }
        
        int i=0,j=1;
        
        while(j<arr.size() && i<j){
            
            if(arr[j]!=arr[i]){
                i++;
                arr[i]=arr[j];
            }
            
            j++;
        }
        
        return len;
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
        int ans = ob.removeDuplicates(arr);
        for (int i = 0; i < ans; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends