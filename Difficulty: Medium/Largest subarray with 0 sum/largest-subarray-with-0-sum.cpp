//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        
        int n=arr.size(),ans=INT_MIN;
        map<int,pair<int,int>>hash;
        vector<int>prefix(n);
        prefix[0]=arr[0];
        
        for(int i=1;i<arr.size();i++){
            prefix[i]+=prefix[i-1]+arr[i];
        }
        
        for(int i=0;i<n;i++){
            
            if(prefix[i]==0){
                ans=max(ans,i+1);
            }
            
            if(hash.find(prefix[i])!=hash.end()){
                hash[prefix[i]].second=i;
            }
            
            else{
                hash[prefix[i]].first=i;
                hash[prefix[i]].second=i;
            }
        }
        
        for(auto itr:hash){
            ans=max(ans,itr.second.second-itr.second.first);
        }
        
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