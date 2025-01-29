//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int low=0,high=arr.size()-1;
        int mid,count=0;
        bool flag=false;
        
        while(low<=high){
            
            mid = low + (high - low)/2;
            
            if(arr[mid] == target){
                flag=true;
                count=1;
                break;
            }
            
            else if(arr[mid] > target){
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        if(!flag){
            return 0;
        }
        low=mid-1,high=mid+1;
        while(low>=0 && arr[mid]==arr[low]){
            count++;
            low--;
        }
        
        while(high<arr.size() && arr[mid]==arr[high]){
            high++;
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