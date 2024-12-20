//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        vector<pair<int,int>>vec;
        
        for(int i=0;i<start.size();i++){
            int start_time=start[i];
            int end_time=end[i];
            
            vec.push_back({end_time,start_time});
        }
        
        int meet=1,prev=0;
        sort(vec.begin(),vec.end());
        
        for(int i=1;i<start.size();i++){
            
            if(vec[i].second > vec[prev].first){
                prev=i;
                meet++;
            }
        }
        return meet;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends