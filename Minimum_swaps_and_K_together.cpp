
// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if(n<=1) return 0;
        
        int i=0;
        while(i<n and arr[i]<=k) i++;
        int j=i+1;
        int count = 0;
        while(j<n){
            if(arr[j]<=k){
                count++;
                swap(arr[i],arr[j]);
                while(i<n and arr[i]<=k) i++;
                
            }
            j++;
        }
        return count;
    }
};
