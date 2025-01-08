//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    bool isPrime(int n){
        
        if(n==0 || n==1){
            return false;
        }
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        
        return true;
    }
    
    vector<int> getPrimes(int n) {
        // code here
        vector<int>vec;
        
        for(int i=2;i<=n-2;i++){
            if(isPrime(n-i) && isPrime(i)){
                vec.push_back(n-i);
                vec.push_back(i);
                sort(vec.begin(),vec.end());
                return vec;
            }
        }
        
        
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    
cout << "~" << "\n";
}
}

// } Driver Code Ends