class Solution {
  public:
    bool checkPerm(vector<int>& a, vector<int>& b) {
        // code here
        stack<int> st;
        int j=0;
        for(int i=0;i<a.size();i++){
            st.push(a[i]);
            
            while(st.size()>0 and st.top()==b[j]){
                j++;
                st.pop();
            }
        }
        return st.size()==0;
    }
};
