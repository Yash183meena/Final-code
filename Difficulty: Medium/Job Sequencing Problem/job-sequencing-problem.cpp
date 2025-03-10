//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n=id.size(),total=0,jobs_done=0;
        vector<pair<int,pair<int,int>>>jobs;
        
        for(int i=0;i<id.size();i++){
            jobs.push_back({profit[i],{deadline[i],id[i]}});
        }
        
        
        sort(jobs.begin(),jobs.end());
        reverse(jobs.begin(),jobs.end());
        
        int max_time=*max_element(deadline.begin(),deadline.end());
        vector<int>fulfill(max_time+1,-1);
        
        for(int i=0;i<n;i++){
            
            int pro=jobs[i].first;
            int dead=jobs[i].second.first;
            int ids=jobs[i].second.second;
            
            if(fulfill[dead]==-1){
                fulfill[dead]=id[i];
                jobs_done++;
                total+=pro;
            }
            
            else{
                int z=dead;
                
                while(z>=1 && fulfill[z]!=-1){
                    z--;
                }
                
                if(z > 0){
                    fulfill[z]=id[i];
                    jobs_done++;
                    total+=pro;
                }
            }
        }
        
        return {jobs_done,total};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends