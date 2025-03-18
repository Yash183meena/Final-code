//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// #include <algorithm>


// } Driver Code Ends

class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        
        int i=0;
        
        for(i=1;i<arr.size();i+=2){
            
            swap(arr[i-1],arr[i]);
        }
    }
};


//{ Driver Code Starts.

int main() {

    int t, n;
    cin >> t; // Input testcases
    cin.ignore();
    while (t--) // While testcases exist
    {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        sort(a.begin(), a.end());
        Solution ob;
        ob.convertToWave(a);

        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends