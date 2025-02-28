//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    void merge(vector<int>& arr, int l, int mid, int r){
        
        int n1 = mid-l+1;
        int n2 = r-mid;
        
        vector<int>left,right;
        
        for(int i=l;i<l+n1;i++){
            left.push_back(arr[i]);
        }
        
        for(int i=mid+1;i<=r;i++){
            right.push_back(arr[i]);
        }
        
        int i=0,j=0,k=l;
        
        while( i<n1 && j<n2){
            
            if( left[i] <= right[j]){
                arr[k] = left[i];
                i++;
                k++;
            }
            
            else{
                arr[k] = right[j];
                j++;
                k++;
            }
        }
        
        while(i<n1){
            arr[k] = left[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k] = right[j];
            k++;
            j++;
        }
        
        
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l < r){
            
            int mid = l + (r - l)/2;
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            
            merge(arr,l,mid,r);
        }
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
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends