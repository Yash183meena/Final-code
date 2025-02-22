//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubble(vector<int>&arr,int n){
        
        if(n==1){
            return;
        }
        
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                swap(arr[i-1],arr[i]);
            }
        }
        
        bubble(arr,n-1);
    }
    
    void bubbleSort(vector<int>& arr) {
        // Your code here
        
        // in the bubble sort largest element in the 1st pass
        // goes to the last index
        int n=arr.size();
        bubble(arr,n);
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
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

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends