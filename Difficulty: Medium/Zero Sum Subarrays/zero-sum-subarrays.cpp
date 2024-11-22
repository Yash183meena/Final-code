//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        map<int,int>mp;
        int ans=0,n=arr.size(),sum=0;
        
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            if(sum==0){
                ans++;
            }
            
            ans+=mp[sum];
            mp[sum]++;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends