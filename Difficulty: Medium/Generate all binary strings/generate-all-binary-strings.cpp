//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    bool check(string str){
        
        for(int i=1;i<str.size();i++){
            
            if(str[i]=='1' && str[i-1]=='1'){
                return false;
            }
        }
        
        return true;
    }
    
    void solve(string str,int n,vector<string>&ans){
        
        if(n==0){
           if(check(str)){
               ans.push_back(str);
           }
            return;
        }
        
        str.push_back('0');
        solve(str,n-1,ans);
        str.pop_back();
        
        str.push_back('1');
        solve(str,n-1,ans);
        str.pop_back();
        
    }
    
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        solve("",num,ans);
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends