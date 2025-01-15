//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        map<int,int>hash;
        int count=0;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;    
        }
        
        for(int i=0;i<arr.size();i++){
            
            int x= target-arr[i];
            
            if(hash.find(x)!=hash.end()){
                count+=hash[x];
            }
            
            if(x == arr[i]){
                count--;
            }
            
            hash[arr[i]]--;
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.

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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends