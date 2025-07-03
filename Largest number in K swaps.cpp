

class Solution {
  public:
    // Function to find the largest number after k swaps.
    void solve(string & s,int ind,int k,string & ans){
        if(k==0 or ind>=s.size()) return;
        char maxch = s[ind];
        for(int i=ind+1;i<s.size();i++){
            if(maxch<s[i]){
                maxch=s[i];
            }
        }
        
        if(maxch!=s[ind])
            k--;
            
            for(int i=ind;i<s.size();i++){
                if(maxch==s[i]){
                    swap(s[i],s[ind]);
                    if(s.compare(ans)>0) ans =s;
                    solve(s,ind+1,k,ans);
                    swap(s[i],s[ind]);
                }
            }
        
    }
    string findMaximumNum(string& s, int k) {
        // code here.
        string ans = s;
        solve(s,0,k,ans);
        return ans;
    }
};
