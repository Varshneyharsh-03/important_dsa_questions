class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int start = 0, maxlen = 1, n = s.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=1;j++){
                int lo = i;
                int hi = i+j;
                
                while(lo>=0 and hi<n and s[lo]==s[hi]){
                    int currlen = hi-lo+1;
                    
                    if(currlen>maxlen){
                        maxlen = currlen;
                        start = lo;
                    }
                    
                    lo--;
                    hi++;
                }
            }
        }
        
        return s.substr(start,maxlen);
        
    }
};
