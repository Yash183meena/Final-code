//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        // code here
        map<int,int>hash;
        
        int left=0,right=0;
        int ans=-1;
        
        for(right=0;right<arr.size();right++){
            
            hash[arr[right]]++;
            
            while(hash.size() > 2){
                
                hash[arr[left]]--;
                
                if(hash[arr[left]]==0){
                    hash.erase(arr[left]);
                }
                
                left++;
            }
            
           
                ans=max(right-left+1,ans);
            //}
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends