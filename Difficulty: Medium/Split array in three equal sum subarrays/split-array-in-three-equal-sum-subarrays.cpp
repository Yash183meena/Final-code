//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        
        int sum=0,n=arr.size(),i=0;
        
        sum=accumulate(arr.begin(),arr.end(),sum);
        
        if(sum%3!=0){
            return {-1,-1};
        }
        
        int t=sum/3,s=0;
        vector<int>vec;
        for(i=0;i<n;i++){
            s+=arr[i];
            
            if(s==t){
                break;
            }
            
        }
        
        if(i<n){
            vec.push_back(i);
        }
        
        s=0;
        for(i=i+1;i<n;i++){
            s+=arr[i];
            
            if(s==t){
                break;
            }
        }
        
        if(i<n){
            vec.push_back(i);
            return vec;
        }
        
        return {1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends