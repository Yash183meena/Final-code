//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void merge(vector<int>& arr, int l, int mid, int r){
        
        vector<int>left;
        vector<int>right;
        
        for(int i=l;i<=mid;i++){
            left.push_back(arr[i]);
        }
        
        for(int i=mid+1;i<=r;i++){
            right.push_back(arr[i]);
        }
        
        int i=0,j=0;
        
        int k=l;
        
        while(i<left.size() && j<right.size()){
            
            if(left[i] < right[j]){
                arr[k] = left[i];
                k++;
                i++;
            }
            
            else{
                arr[k]=right[j];
                k++;
                j++;
            }
        }
        
        if(i==left.size()){
            while(j<right.size()){
                arr[k]=right[j];
                k++;
                j++;
            }
        }
        
        else if(j==right.size()){
            while(i<left.size()){
                arr[k]=left[i];
                k++;
                i++;
            }
        }
    }
   
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        int mid=l + (r-l)/2;
        
        if(l<r){
            
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