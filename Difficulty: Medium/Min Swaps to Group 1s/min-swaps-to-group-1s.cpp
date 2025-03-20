//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        
        int ones=0;
        for(auto ele:arr){
            if(ele==1){
                ones++;
            }
        }
        
        if(ones==0){
            return -1;
        }
        
        int window_size=ones;
        
        int left=0,right=0,swaps=INT_MAX;
        ones=0;
        
        while(right<arr.size()){
            
            if(arr[right]==1){
                ones++;
            }
            
            if(right-left+1==window_size){
                swaps=min(swaps,window_size-ones);
                if(arr[left]==1){
                    ones--;
                }
                left++;
            }
            
            right++;
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.minSwaps(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends