// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=n-1;
        int count=0;
        if(arr[0]==0) return -1;
        
        while(i>0){
            bool flag=false;
            for(int j=0;j<i;j++){
                if(arr[j]+j>=i){
                    flag=true;
                    i=j;
                    break;
                }
            }
            if(flag==false){
                return -1;
            }
            else{
                count++;
            }
        }
        return count;
    }
};

