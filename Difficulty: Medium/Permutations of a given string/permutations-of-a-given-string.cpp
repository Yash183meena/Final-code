//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void solve(string &s,int index,string str,set<string>&st){
        
        if(index>=s.size()){
            st.insert(str);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            
           swap(s[i],s[index]);
           
           str.push_back(s[index]);
           solve(s,index+1,str,st);
           
           str.pop_back();
           swap(s[index],s[i]);
        }
    }
    
    vector<string> find_permutation(string &s) {
        // Code here there
        set<string>st;
        vector<string>permututations;
        string str="";
        
        solve(s,0,str,st);
        
        for(auto permutuation : st){
            permututations.push_back(permutuation);
        }
        
        return permututations;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends