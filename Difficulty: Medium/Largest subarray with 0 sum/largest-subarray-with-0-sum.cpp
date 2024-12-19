//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        
        map<int,pair<int,int>>mp;
        int prefix=0;
        
        for(int i=0;i<arr.size();i++){
            
            prefix+=arr[i];
            
            if(mp.find(prefix)!=mp.end()){
                mp[prefix].second=i;
            }
            
            else{
                mp[prefix]={i,i};
            }
        }
        
        int ans=INT_MIN;
        
        for(auto itr:mp){
            
            if(itr.first==0){
                ans=max(ans,itr.second.second+1);
            }
            
            ans=max(ans,itr.second.second-itr.second.first);
        }
        
       // cout<<ans;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends