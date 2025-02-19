//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        
        int platforms=0,busy=0;
        vector<pair<int,char>>trains;
        
        for(int i=0;i<arr.size();i++){
            trains.push_back({arr[i],'a'});
        }
        
        for(int i=0;i<dep.size();i++){
            trains.push_back({dep[i],'d'});
        }
        
        sort(trains.begin(),trains.end());
        
        for(int i=0;i<trains.size();i++){
            
            if(trains[i].second=='a'){
                busy++;
                platforms=max(platforms,busy);
            }
            
            else{
                busy--;
            }
        }
        
        return platforms;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends