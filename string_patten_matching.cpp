class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    vector<int> createLps(string s){
        int n = s.size();
        
        vector<int> arr(n);
        
        arr[0] = 0;
        int len = 0;
        
        int i=1;
        
        while(i<n){
            if(s[len]==s[i]){
                len++;
                arr[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = arr[len-1];
                }
                else{
                    arr[i] = 0;
                    i++;
                }
            }
        }
        return arr;
    }
    bool areRotations(string &s1, string &s2) {
        // Your code here
        int n = s1.size();
        int m = s2.size();
        
        if(n!=m) return false;
        
        string text = s1 + s1 ;
        string pat = s2;
        
        vector<int> lps = createLps(pat);
        
        
        int i=0;
        int j=0;
        
        while(i<2*n){
            
            if(text[i]==pat[j]){
                i++;
                j++;
            }
            else if (j==m){
                return true;
            }
            else if (text[i]!=pat[j]){
                
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
                
            }
        }
        return false;
    }
