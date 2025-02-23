//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        
        if(low < high){
            int pivot = partition(arr,low,high);
        
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        
        int pivot = low;
        
        int p=low,q=high;
        
        while( p < q){
            
            while( arr[p] <= arr[pivot]){
                p++;
            }
        
            while(arr[q] > arr[pivot]){
                q--;
            }
            
            if(p < q){
                swap(arr[p],arr[q]);
            }
        }
       
        swap(arr[q],arr[pivot]);
        
        //after the 1st pass q is in our original position
        return q;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends