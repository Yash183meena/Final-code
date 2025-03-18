//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        
        int window_size=0;
        int ones=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                ones++;
            }
        }
        
        if(ones==0){
            return -1;
        }
        
        window_size=ones;
        int sum=0,s=0;
        
        int left=0,right=0;
        
        while(right<arr.size()){
            
            s+=arr[right];
            
            if(right-left+1==window_size){
                sum=max(sum,s);
                s-=arr[left];
                left++;
            }
            
            right++;
        }
 
        return window_size-sum;
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