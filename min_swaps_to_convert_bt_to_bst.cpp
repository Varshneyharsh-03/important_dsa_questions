// User function Template for C++
class Solution {
  public:
    void inorder_traversal(vector<int>& arr,vector<int>& inorder,int i){
        if(i>=arr.size()) return ;
        
        inorder_traversal(arr,inorder,2*i+1);
        inorder.push_back(arr[i]);
        inorder_traversal(arr,inorder,2*i+2);
    }
    int minSwaps(vector<int>& temp) {
        // Write your code here
        vector<int> inorder;
        inorder_traversal(temp,inorder,0);
        int n=inorder.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({inorder[i],i});
        }
        int count=0;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(i==arr[i].second) continue;
            else{
                swap(arr[i].first,arr[arr[i].second].first);
                swap(arr[i].second,arr[arr[i].second].second);
                if(i!=arr[i].second) i--;
                count++;
            }
        }
        return count;
      
    }
};
