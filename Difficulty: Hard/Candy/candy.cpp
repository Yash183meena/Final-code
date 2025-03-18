//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1]){
                right[i]=right[i+1] + 1;
            }
        }
        
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                left[i] = 1 + left[i-1];
            }
        }
        
        int candies=0;
        
        for(int i=0;i<n;i++){
            candies+=max(left[i],right[i]);
        }
        
        return candies;
    }
};



//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr = inputLine();

        Solution obj;
        cout << obj.minCandy(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends