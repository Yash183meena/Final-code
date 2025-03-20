//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        //using an deque data structure
        deque<int>deq;
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++){
            
            //step1:-->to check if the element outside window remove it
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            
            //step2:-->check only the lement greater should be inserted
            while(!deq.empty() && arr[deq.back()] <= arr[i]){
                deq.pop_back();
            }
            
            //step3:-->insert the element at the back of the queue
            deq.push_back(i);
            
            //step4:-->insert the only if window size is sufficent
            if(i-k+1>=0){
                ans.push_back(arr[deq.front()]);
            }
        }
        
        for(auto ele:ans){
            cout<<ele<<" ";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends