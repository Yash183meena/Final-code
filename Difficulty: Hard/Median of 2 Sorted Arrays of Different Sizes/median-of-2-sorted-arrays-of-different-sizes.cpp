//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n=a.size(),m=b.size();
        
        if(n > m){
            return medianOf2(b,a);
        }
        
        int low=0,high=n;
        
        while(low<=high){
            
            int px = low + (high-low)/2;
            
            int py = (m+n+1)/2-px;
            
            int x1 = px==0?INT_MIN:a[px-1];
            int x2 = py==0?INT_MIN:b[py-1];
            
            int x3 = px==n?INT_MAX:a[px];
            int x4 = py==m?INT_MAX:b[py];
            
            
            if( x1<=x4 && x2<=x3){
                
                if((m+n)%2==1){
                    return max(x1,x2);
                }
                
                return (max(x1,x2) + min(x3,x4))/2.0;
            }
            
            else if(x1 >= x4){
                high = px-1;
            }
            
            else{
                low=px+1;
            }
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends