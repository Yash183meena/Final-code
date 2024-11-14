//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void merge(vector<int>&arr, int left, int mid,int right){
        
        int n1 = mid-left+1;
        int n2 = right-mid;
        
        vector<int>lt(n1),rt(n2),ans;
        
        for(int i=0;i<n1;i++){
            lt[i]=arr[left+i];
        }
        
        for(int j=0;j<n2;j++){
            rt[j]=arr[mid+j+1];
        }
        
        int i=0,j=0;
        
        while(i<n1 && j<n2){
            
            if( lt[i] < rt[j] ){
                ans.push_back(lt[i]);
                i++;
            }
            
            else{
                ans.push_back(rt[j]);
                j++;
            }
        }
        
        if(i==n1){
            for(;j<n2;j++){
                ans.push_back(rt[j]);
            }
        }
        
        else if(j==n2){
            for(;i<n1;i++){
                ans.push_back(lt[i]);
            }
        }
        
        for(int i=0;i<ans.size();i++){
            arr[left+i]=ans[i];
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