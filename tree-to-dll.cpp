/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
  Node* prev=nullptr ;
  Node* head = nullptr;
  
  void solve(Node* root){
      if(root==nullptr) return;
      solve(root->left);
      
      if(prev==nullptr){
          head = root;
      }
      else{
         root->left = prev;
         prev->right=root;
      }
      prev = root;
      
      solve(root->right);
  }
    Node* bToDLL(Node* root) {
        // code here
        solve(root);
        return head;
        
    }
};
