// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    int solve(Node* root,map<Node*,int>& mp){
        if(root==nullptr) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int include=root->data,exclude=0;
        
        if(root->left){
            include += solve(root->left->left,mp)+solve(root->left->right,mp);
        }
        
        if(root->right){
            include += solve(root->right->left,mp) + solve(root->right->right,mp);
        }
        
        exclude += solve(root->left,mp) + solve(root->right,mp);
        return mp[root] =
        max(include,exclude);
    }
    int getMaxSum(Node *root) {
       // Add your code here
        if(root==nullptr){
            return 0;
        }
        map<Node*,int> mp;
        return solve(root,mp);
    }
};
