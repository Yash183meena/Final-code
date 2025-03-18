//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // your code here
        int n=arr.size();
        int m=n/2;

        //VOTING MOORE APPROACH
        int cnt=0,ele;
        
        
        for(int i=0;i<n;i++){
            
            if( cnt==0 ){
                cnt=1;
                ele=arr[i];
            }
            
            else if(ele == arr[i]){
                cnt++;
            }
            
            else{
                cnt--;
            }
            
        }
        
        int cnt1=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                cnt1++;
            }
        }
        
        if(cnt1 > n/2){
            return ele;
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
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends