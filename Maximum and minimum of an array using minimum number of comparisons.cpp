// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int minVal;
        int maxVal;
        int i;
        int n=arr.size();
        if(n==1) return {arr[0],arr[0]};
        
        if(n%2==0){
            if(arr[0]>arr[1]) {maxVal= arr[0]; minVal = arr[1];}
            else {maxVal = arr[1]; minVal = arr[0]; }
            i=2;
        }
        else{
            minVal = maxVal = arr[0];
            i=1;
        }
        
        while(i<n-1){
            int localmin;
            int localmax;
            
            if(arr[i+1]>arr[i]){
                localmax = arr[i+1];
                localmin = arr[i];
                
            }
            else {
                localmax = arr[i];
                localmin = arr[i+1];
            }
            
            if(minVal > localmin) minVal = localmin;
            if(maxVal < localmax) maxVal = localmax;
            i+=2;
        }
        
        return {minVal,maxVal};
    }
};
