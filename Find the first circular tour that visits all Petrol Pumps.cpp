int solve(vector<int>& gas,vector<int>& cost){
  int n = cost.size();
  int sum = 0;
  int total = 0;
  int start = 0;

  for(int i=0;i<n;i++){
    sum+=gas[i]-cost[i];
    total+=gas[i]-cost[i];
    if(sum<0){
      sum=0;
      start=i+1;
    }
  }
  if(total<0) return -1;
  return start;
}
