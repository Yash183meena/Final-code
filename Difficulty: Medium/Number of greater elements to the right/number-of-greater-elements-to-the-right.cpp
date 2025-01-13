//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        
        stack<int>stk,st;
        vector<int>greater(n);
        
        greater[n-1]=0;
        stk.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            
            int current = arr[i];
            int count = 0;
            
            while(!stk.empty()){
                
                if(stk.top() > arr[i]){
                    count++;
                }
                st.push(stk.top());
                stk.pop();
            }
            
            greater[i]=count;
            
            while(!st.empty()){
                stk.push(st.top());
                st.pop();
            }
            
            stk.push(current);
        }
        
        vector<int>vec;
        for(int i=0;i<queries;i++){
            int index=indices[i];
            vec.push_back(greater[index]);
        }
        
        // for(auto ele : vec){
        //     cout<<ele<<" ";
        // }
        
        return vec;
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
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends