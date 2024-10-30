//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        vector<int>prefix;
        int sum=0,ans=INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            prefix.push_back(sum);
            if(sum==k){
                ans=i+1;
            }
            if(arr[i]==k){
                ans=max(ans,1);
            }
        }
        
        int i=0,j=i+1;
        
        while(i<j && j<arr.size() && i<arr.size()){
            
            if(prefix[j]-prefix[i]==k){
                //cout<<j<<" "<<i;
                ans=max(j-i,ans);
                j++;
            }
            
            else if(prefix[j]-prefix[i]>k){
                i++;
            }
            
            else if(prefix[j]-prefix[i]<k){
                j++;
            }
            
            if(i==j){
                j++;
            }
        }
        
        return ans==INT_MIN? 0 : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
    }

    return 0;
}

// } Driver Code Ends