class Solution {
  public:
  vector<Node*> ans;
    string solve(Node* root,map<string,int>& mp){
        if(root==nullptr) return "$";
       /*
       if leaf node is not counted then add this 
        if(root->left == nullptr and root->right == nullptr){
          return to_string(root->data);
        }
       */
        
        
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
