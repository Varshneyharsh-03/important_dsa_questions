// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int count = 0;
        int i=0;
        int n = arr.size();
        
        while(i<n and arr[i]<=k) i++;
        
        int j=i+1;
        
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
