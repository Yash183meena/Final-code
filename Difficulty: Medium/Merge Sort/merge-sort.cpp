//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void merge(vector<int>& arr,int left,int mid,int right){
        
        int n1=mid-left+1;
        int n2=right-mid;
        
        vector<int>arr1,arr2;
        
        for(int i=0;i<n1;i++){
            arr1.push_back(arr[left+i]);
        }
        
        for(int j=0;j<n2;j++){
            arr2.push_back(arr[mid+j+1]);
        }
        
        int i=0,j=0,k=left;
        
        while(i<n1 && j<n2){
            if(arr1[i] > arr2[j]){
                arr[k]=arr2[j];
                k++;
                j++;
            }
            else if(arr1[i] <= arr2[j]){
                arr[k]=arr1[i];
                i++;
                k++;
            }
        }
        
        if(i==n1){
            for(;j<n2;j++){
                arr[k]=arr2[j];
                k++;
            }
        }
        
        if(j==n2){
            for(;i<n1;i++){
                arr[k]=arr1[i];
                k++;
            }
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int mid=l+(r-l)/2;
        
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