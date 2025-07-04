
class Solution {
  public:
  int no_of_zeros(int n){
      int ans = 0;
        for(int i=5;i<=n;i*=5){
            ans += n/i;
        }
        return ans;
  }
    int findNum(int n) {
        // complete the function here
        
        int lo=0;
        int hi = 5*n;
        
        while(lo<hi){
            
            int mid = (lo+hi)/2;
            int count = no_of_zeros(mid);
            if(count >= n)  hi=mid;
            else {
                lo=mid+1;
            }
        }
        return lo;
        
    }
};
