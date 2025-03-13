//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        
        int swaps=0;
        vector<pair<int,int>>vec;
        
        //step1:-->pushing all elements with index in the vector
        for(int i=0;i<arr.size();i++){
            vec.push_back({arr[i],i});
        }
        
        //step2:-->sort that vector acc to elements
        sort(vec.begin(),vec.end());
        
        //step3:--We can be track which elements is swapped out after the sorting
        for( int i=0;i<vec.size();i++){
            
            if( i!=vec[i].second ){
                swaps++;
                swap(vec[i],vec[vec[i].second]);
                i--;
            }
        }
        
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