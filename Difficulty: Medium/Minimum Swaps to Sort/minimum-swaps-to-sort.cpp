//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int swp=0;
        vector<pair<int,int>>vec;
        
        for(int i=0;i<arr.size();i++){
            vec.push_back({arr[i],i});
        }
        
        sort(begin(vec),end(vec));
        
        for(int i=0;i<arr.size();i++){
            if(i!=vec[i].second){
                //this is due to only distinct elements is available
                swap(vec[vec[i].second],vec[i]);
                swp++;
                i--;
            }
        }
        
        return swp;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends