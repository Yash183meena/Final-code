//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    static bool cmp(int num1,int num2){
               
        string s1 = to_string(num1) + to_string(num2);
        
        string s2 = to_string(num2) + to_string(num1);
        
        return s1>s2;
    }
     
    string findLargest(vector<int> &arr) {
        // code here
        
        sort(arr.begin(),arr.end(),cmp);
        string str="";
        for(auto ele :arr){
            str+=to_string(ele);
        }
        
        if(str[0]=='0'){
            return "0";
        }
        
        return str;
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

        Solution ob;
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends