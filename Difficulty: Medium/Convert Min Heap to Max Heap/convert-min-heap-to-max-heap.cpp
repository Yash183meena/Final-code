//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void heapify(vector<int> &arr, int N,int idx){
       
       int parent=idx;
       int left=2*idx+1;
       int right=2*idx+2;
       
        if(left<N && arr[left] > arr[parent]){
            parent=left;
        }
        
        if(right<N && arr[right]> arr[parent]){
            parent=right;
        }
        
        if(parent!=idx){
            swap(arr[idx],arr[parent]);
            heapify(arr,N,parent);
        }
        
    }
   
    void convertMinToMaxHeap(vector<int> &arr, int N){
      
        for(int idx=N/2-1;idx>=0;idx--){
            heapify(arr,N,idx);
        }
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