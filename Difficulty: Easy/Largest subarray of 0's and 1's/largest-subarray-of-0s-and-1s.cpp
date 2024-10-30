//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution {
  public:
    int maxLen(int arr[], int n) {
        // Your code here
        
        map<int,pair<int,int>>mp;
        int sum=0,ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        
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
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends