
int ans ;

int height(Node* root){
  if(root==nullptr) return 0;

  int left = height(root->left);
  int right = height(root->right);
  ans = max(ans,1+left+right);
  return 1+max(left,right);
}
