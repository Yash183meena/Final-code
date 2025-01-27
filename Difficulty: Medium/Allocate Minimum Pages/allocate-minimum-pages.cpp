//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isSafe(vector<int> &arr, int k,int mid){
        
        int k1=1,sum=0;
        
        for(int i=0;i<arr.size();i++){
            if(sum + arr[i] > mid ){
                
                k1++;
                if( k1 > k){
                    return false;
                }
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int books=arr.size();
        int min_pages=INT_MAX;
        
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        if( books < k){
            return -1;
        }
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(isSafe(arr,k,mid)){
                high=mid-1;
                min_pages=mid;
            }
            
            else{
                low=mid+1;
            }
        }
        
        return min_pages;
    }
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends