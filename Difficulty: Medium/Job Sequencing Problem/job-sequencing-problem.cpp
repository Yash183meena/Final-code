//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    static bool cmp(pair<int,pair<int,int>>&a , pair<int,pair<int,int>>&b){
        
        return a.second.second > b.second.second;
    }
    
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                       vector<int> &profit) {
        // code here
        
        int j=0,p=0;
        
        int maxTime=*max_element(deadline.begin(),deadline.end());
        vector<pair<int,pair<int,int>>>jobs;
        
        vector<int>jobSchedule(maxTime,-1);
        
        for(int i=0;i<id.size();i++){
            jobs.push_back({id[i],{deadline[i],profit[i]}});
        }
        
        sort(jobs.begin(),jobs.end(),cmp);
        
        for(int i=0;i<id.size();i++){
            
            int job_id = jobs[i].first;
            int job_deadline =jobs[i].second.first;
            int job_profit=jobs[i].second.second;
            
            if(jobSchedule[job_deadline-1]==-1){
                j++;
                p+=job_profit;
                jobSchedule[job_deadline-1]=job_id;
            }
            
            else{
                
                while(job_deadline-1 >= 0){
                    
                    if(jobSchedule[job_deadline-1]==-1){
                        j++;
                        p+=job_profit;
                        jobSchedule[job_deadline-1]=job_id;
                        break;
                    }
                    
                    job_deadline--;
                }
            }
        }
        
        return {j,p};
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