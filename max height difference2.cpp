int minDiff(vector<int>arr,int k){
  
  int n = arr.size();
  sort(arr.begin(),arr.end());
  int tmin = arr[0];
  int tmax = arr[n-1];

  int ans = tmax - tmin;

  for(int i=1;i<n;i++){
    if(arr[i]-k<0) continue;
    tmin = min(arr[0]+k,arr[i]-k);
    tmax = max(arr[n-1]-k,arr[i]+k);
    ans = min(ans,tmax - tmin);
  }
  return ans;
  
}
