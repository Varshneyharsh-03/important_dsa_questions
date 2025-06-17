// User function Template for C++

class Solution {
  public:
    bool isPal(string str){
        int lo = 0;
        int hi = str.size()-1;
        
        while(lo<hi){
            if(str[lo]!=str[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    void solve(string s ,vector<vector<string>>& ans,vector<string>& temp){
        int n = s.size();
        if(n==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=0 ; i<n;i++){
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(isPal(left)){
                temp.push_back(left);
                solve(right,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        solve(S,ans,temp);
        return ans;
    }
};
