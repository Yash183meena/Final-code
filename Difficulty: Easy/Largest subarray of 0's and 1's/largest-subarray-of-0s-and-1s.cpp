//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        
        //we convert this question to replace the 
        //zeroes to -1 and find the largest array with sum 0
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        
        map<int,int>hash;
        int len=0,prefix=0;
        
        for(int i=0;i<arr.size();i++){
            prefix+=arr[i];
            
            if(prefix==0){
                len=max(len,i+1);
            }
            
            if(hash.find(prefix)!=hash.end()){
                len=max(len,i-hash[prefix]);
            }
            
            if(hash.find(prefix)==hash.end()){
                hash[prefix]=i;
            }
        }
        
        return len;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends