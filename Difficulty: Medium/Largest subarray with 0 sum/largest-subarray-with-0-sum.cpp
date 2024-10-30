//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        
        map<int,pair<int,int>>mp;
        int sum=0,ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                ans=max(ans,i+1);
            }
                
            if(mp.find(sum)!=mp.end()){
                mp[sum].second=i;
            }
            else{
                mp[sum].first=i;
                mp[sum].second=i;
            }
        }
        
        for(auto itr:mp){
            ans=max(ans,itr.second.second-itr.second.first);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends