//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        
        int n=arr.size();
        int low = 0,high=arr.size()-1;
        
        while(low<=high){
            
            bool a=false,b=false,c=false,d=false;
            if(low+1<n && arr[low]==arr[low+1]){
                a=true;
            }
            if(low-1>=0 && arr[low]==arr[low-1]){
                b=true;
            }
            if(!a && !b){
                return arr[low];
            }
            
            else{
                low+=2;
            }
            
            if(high-1>=0 && arr[high]==arr[high-1]){
                c=true;
            }
            
            if(high+1<n && arr[high]==arr[high+1]){
                d=true;
            }
            if(!c && !d){
                return arr[high];
            }
            
            else{
                high-=2;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.findOnce(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends