//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int zero=0,n=arr.size();
        int product=1;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]!=0){
                product*=arr[i];
            }
            
            else if(arr[i]==0){
                zero++;
            }
        }
        
        vector<int>vec;
        
        for(int i=0;i<n;i++){
            
            if(zero==1 && arr[i]==0 ){
                vec.push_back(product);
            }
            
            else if(zero>=1){
                vec.push_back(0);
            }
            
            else{
                vec.push_back(product/arr[i]);
            }
        }
        
        return vec;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends