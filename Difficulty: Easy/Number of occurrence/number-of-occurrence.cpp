//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int mid,idx=-1,count=0;
        int low=0,high=arr.size()-1;
        
        while(low <= high){
            
            mid = low + (high - low)/2;
            
            if(arr[mid] == target){
                idx=mid;
                count++;
                break;
            }
            
            else if(arr[mid] > target){
                high=mid-1;
            }
            
            else if(arr[mid] < target){
                low=mid+1;
            }
        }
        
        if(idx==-1){
            return 0;
        }
        
        int i=idx-1,j=idx+1;
        
        while(i>=0 && arr[i]==target){
            count++;
            i--;
        }
        
        while(j<arr.size() && arr[j]==target){
            j++;
            count++;
        }
        
        return count;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends