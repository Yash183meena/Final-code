//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        
        //three number with maximum product
        
        //done by maintaing the 5 variables
        
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] > max1){
                max3=max2;
                max2=max1;
                
                max1=arr[i];
            }
            else if(arr[i] > max2){
                max3=max2;
                max2=arr[i];
            }
            else if(arr[i]>max3){
                max3=arr[i];
            }
            
            if(arr[i] < min1){
                min2=min1;
                min1=arr[i];
            }
            else if(arr[i] < min2){
                min2=arr[i];
            }
    
        }
        
        return max(max1*min1*min2,max1*max2*max3);
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends