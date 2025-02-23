//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,int>&a,pair<double,int>&b){
    return a.first > b.first;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<double,int>> ratio;

    for(int i=0; i<val.size(); i++){
        double r = (double) val[i] / wt[i];  // Corrected this line
        ratio.push_back({r, i});
    }

    double profit = 0;

    sort(ratio.begin(), ratio.end(), cmp);

    for(int i=0; i<ratio.size(); i++){
        int idx = ratio[i].second;

        if(capacity >= wt[idx]){
            profit += val[idx];
            capacity -= wt[idx];
        } else {
            profit += ratio[i].first * capacity;
            break;
        }
    }

    return profit;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends