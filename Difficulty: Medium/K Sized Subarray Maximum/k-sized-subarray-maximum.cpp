//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        //ds -->deque
        
        vector<int>window;
        deque<int>deq;
        
        for(int i=0;i<arr.size();i++){
            
            //step1--> consider k window eleemnts
            while(!deq.empty() && i-deq.front()>=k){
                deq.pop_front();
            }
            
            //step2-->pop if the last elements are less than current
            while(!deq.empty() && arr[deq.back()] < arr[i]){
                deq.pop_back();
            }
            
            //step3-->push current in the deque
            deq.push_back(i);
            
            //step4-->check if the size of windo is k
            if(i+1-k >=0){
                window.push_back(arr[deq.front()]);
            }
        }
        
        return window;
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