class Solution {
  public:
  vector<Node*> ans;
    string solve(Node* root,map<string,int>& mp){
        if(root==nullptr) return "$";
       
        
        
        string s = to_string(root->data) + solve(root->left,mp) + solve(root->right,mp);
        mp[s]++;
        if(mp[s]==2){
            ans.push_back(root);
        }
        return s;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        map<string,int> mp;
        solve(root,mp);
        return ans;
        
    }
};
