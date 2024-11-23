//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int n=s.size(),i=0,j=0,count=0;
        map<char,int>mp;
        mp[s[0]]++;

        while(i<n && j<n){
             
            if(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+=n-j;
                mp[s[i]]--;
                i++;
            }

            else{
                j++;
                if(j<n){
                    mp[s[j]]++;
                }
            }
        }
        
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends