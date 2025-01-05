//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        
        vector<pair<int,int>>vec;
        int swaps=0;
        
        for(int i=0;i<arr.size();i++){
            vec.push_back({arr[i],i});
        }
        
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<vec.size();i++){
            
            if(vec[i].second!=i){
                swap(vec[i],vec[vec[i].second]);
                i--;
                swaps++;
            }
        }
        
        //cout<<swaps<<endl;
        
        return swaps;
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