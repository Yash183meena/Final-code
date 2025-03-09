//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    void heapify(int idx,vector<int> &arr, int N){
        
        int left = 2*idx+1;
        int right = 2*idx + 2;
        int largest = idx;
        
        if(left<N && arr[left] > arr[largest]){
            largest=left;
        }
        
        if(right<N && arr[right] > arr[largest]){
            largest=right;
        }
        
        if(idx!=largest){
            swap(arr[idx],arr[largest]);
            
            heapify(largest,arr,N);
        }
    }
    
    void BuildHeap(vector<int>&arr,int N){
        
        
        for(int i=N/2-1;i>=0;i--){
            heapify(i,arr,N);
        }
        
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N){
           
           BuildHeap(arr,N);
    }
    
};



//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends