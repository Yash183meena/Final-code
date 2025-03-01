//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    void solve(int row,int col,int n,vector<vector<int>> &mat,vector<vector<bool>>&visited,string str,
        vector<string>&vec){
        
        if(row == n-1 && col==n-1){
            vec.push_back(str);
            return;
        }
        
        if(col+1<n && !visited[row][col+1] && mat[row][col+1]==1){
            
            visited[row][col+1]=true;
            str.push_back('R');
            solve(row,col+1,n,mat,visited,str,vec);
            str.pop_back();
            visited[row][col+1]=false;
            
        }
        
        if(col-1>=0 && !visited[row][col-1] && mat[row][col-1]==1){
            
            str.push_back('L');
            visited[row][col-1]=true;
            solve(row,col-1,n,mat,visited,str,vec);
            str.pop_back();
            visited[row][col-1]=false;
        }
        
        if(row+1<n && !visited[row+1][col] && mat[row+1][col]==1){
            str.push_back('D');
            visited[row+1][col]=true;
            solve(row+1,col,n,mat,visited,str,vec);
            str.pop_back();
            visited[row+1][col]=false;
        }
        
        if(row-1>=0 && !visited[row-1][col] && mat[row-1][col]==1){
            str.push_back('U');
            visited[row-1][col]=true;;
            solve(row-1,col,n,mat,visited,str,vec);
            str.pop_back();
            visited[row-1][col]=false;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        
        int n=mat.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<string>vec;
        string str="";
        visited[0][0]=true;
        solve(0,0,n,mat,visited,str,vec);
        
        return vec;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends