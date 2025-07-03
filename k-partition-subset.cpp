class Solution {
public:
    bool solve(int reqsum,int ind,int sum,int bucket,int k,vector<int>& nums,vector<int>& visit){
        if(bucket==k) return true;
        if(reqsum==sum) return solve(reqsum,0,0,bucket+1,k,nums,visit);
        if(ind>=nums.size() or sum>reqsum) return false;

        if(visit[ind]==1){
            return solve(reqsum,ind+1,sum,bucket,k,nums,visit);
        }
        else{
            sum+=nums[ind];
            visit[ind]=1;
            int take = solve(reqsum,ind+1,sum,bucket,k,nums,visit);
            sum-=nums[ind];
            visit[ind]=0;
            int not_take = solve(reqsum,ind+1,sum,bucket,k,nums,visit);
            return take || not_take;
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> visit(n,0);
        int sum=0;
        for(auto num : nums) sum+=num;
        if(sum%k!=0) return false;
        int reqsum=sum/k;
        return solve(reqsum,0,0,0,k,nums,visit);
    }
};
