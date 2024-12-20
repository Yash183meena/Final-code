//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string>st(wordList.begin(),wordList.end());
        
        queue<pair<int,string>>que;
        
        if(st.find(targetWord)==st.end() ){
            return 0;
        }
        
        que.push({1,startWord});
        
        
        
        while(!que.empty()){
            
            string current = que.front().second;
            int level= que.front().first;
            que.pop();
            
            if( current  == targetWord ){
                return level;
            }
            
            for(int i=0;i<current.size();i++){
                
                char original = current[i];
                
                for(char ch='a';ch<='z';ch++){
                    
                    current[i]=ch;
                    
                    if(st.find(current)!=st.end()){
                        
                        st.erase(current);
                        que.push({level+1,current});
                    }
                }
                
                current[i]=original;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends