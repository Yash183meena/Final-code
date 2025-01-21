//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    vector<string>ans;
    
    int isSafe(string &s){
        
        for(int i=1;i<s.size();i++){
            if(s[i]=='1' && s[i-1]=='1'){
                return false;
            }
        }
        
        return true;
    }
    
    void generate(int idx,int num,string str){
        
        if(str.size()==num){
            if(isSafe(str)){
                ans.push_back(str);
            }
            return;
        }
        
       // for(int i=idx;i<num;i++){
            
            str.push_back('0');
            generate(idx+1,num,str);
            str.pop_back();
            
            str.push_back('1');
            generate(idx+1,num,str);
            str.pop_back();
       // }
    }
    
    vector<string> generateBinaryStrings(int num){
        //Write your code
        
        generate(0,num,"");
        
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