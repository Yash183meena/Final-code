//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    void solve(vector<vector<int>> &mat,vector<vector<bool>>&visited,int row,int col,int n,
    vector<char>&path,set<vector<char>>&paths){
        
        if(row == n-1 && col == n-1){
            paths.insert(path);
            return;
        }
        
        if(row+1<n && !visited[row+1][col] && mat[row+1][col]==1 ){
            visited[row+1][col]=true;
            path.push_back('D');
            solve(mat,visited,row+1,col,n,path,paths);
            path.pop_back();
            visited[row+1][col]=false;
        }
        
        if(row-1>=0 && !visited[row-1][col] && mat[row-1][col]==1){
            visited[row-1][col]=true;
            path.push_back('U');
            solve(mat,visited,row-1,col,n,path,paths);
            path.pop_back();
            visited[row-1][col]=false;
        }
        
        if(col-1>=0 && !visited[row][col-1] && mat[row][col-1]==1){
            visited[row][col-1]=true;
            path.push_back('L');
            solve(mat,visited,row,col-1,n,path,paths);
            path.pop_back();
            visited[row][col-1]=false;
        }
        
        if(col+1<n && !visited[row][col+1] && mat[row][col+1]==1){
            visited[row][col+1]=true;
            path.push_back('R');
            solve(mat,visited,row,col+1,n,path,paths);
            path.pop_back();
            visited[row][col+1]=false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        
        int n = mat.size();
        vector<vector<bool>>visited(n+1,vector<bool>(n+1,false));
        
        vector<char>path;
        set<vector<char>>paths;
        
        visited[0][0]=true;
        solve(mat,visited,0,0,n,path,paths);
        
        vector<string>vec;
        
        for(auto pths:paths){
            string str="";
            for(auto ele:pths){
                str.push_back(ele);
            }
            vec.push_back(str);
        }
        
        
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