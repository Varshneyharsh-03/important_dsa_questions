class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
    int inc = 1, dsc = 1;
    
    int n = arr.size();
    
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]) inc = dsc+1;
        else if (arr[i]<arr[i-1]) dsc = inc+1;
    }
    
    return max(inc,dsc);
}

};
