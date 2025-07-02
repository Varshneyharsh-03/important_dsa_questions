class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=height[0];
        suff[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            pre[i]=max(height[i],pre[i-1]);
            suff[n-i-1]=max(height[n-i-1],suff[n-i]);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans += min(pre[i],suff[i])-height[i];
        }

        return ans;
    }
};
